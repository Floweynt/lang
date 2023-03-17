class lang_type <string val> {
  string enum_name = val;
}

class integral_type<string val, int bit_width, bit unsigned> : lang_type<val> {
  int width = bit_width;
  bit is_unsigned = unsigned;
}

def boolean : integral_type<"BOOL"                  , 1,  false>;
def i8      : integral_type<"INTEGRAL_SIGNED_B8"    , 8,  false>;
def i16     : integral_type<"INTEGRAL_SIGNED_B16"   , 16, false>;
def i32     : integral_type<"INTEGRAL_SIGNED_B32"   , 32, false>;
def i64     : integral_type<"INTEGRAL_SIGNED_B64"   , 64, false>;
def intmax  : integral_type<"INTEGRAL_MAX"          , 64, false>;
def u8      : integral_type<"INTEGRAL_UNSIGNED_B8"  , 8,  true>;
def u16     : integral_type<"INTEGRAL_UNSIGNED_B16" , 16, true>;
def u32     : integral_type<"INTEGRAL_UNSIGNED_B32" , 32, true>;
def u64     : integral_type<"INTEGRAL_UNSIGNED_B64" , 64, true>;
def uintmax : integral_type<"INTEGRAL_UMAX"         , 64, true>;

class operation<lang_type target_type> {
  lang_type target = target_type;
}

class promotion_operation<bit zext, lang_type target_type> : operation<target_type> {
  bit is_zext = zext;
}

class binary_operator<string op, lang_type lhs, lang_type rhs, lang_type result> {
  string operator = op;
  lang_type lhs_type = lhs;
  lang_type rhs_type = rhs;
  lang_type result_type = result;
}

// concrete classes
class arithmetic_binary_operator<string op, integral_type lhs, integral_type rhs, string llvm_function> 
    : binary_operator<op, lhs, rhs, !if(!gt(lhs.width, rhs.width), lhs, rhs)> {
  string llvm_function_name = llvm_function;
}

class predicate_binary_operator<string op, integral_type lhs, integral_type rhs, string llvm_function> 
    : binary_operator<op, lhs, rhs, boolean> {
  string llvm_function_name = llvm_function;
}

class trivial_assignment_binop<string op, lang_type assigned> 
    : binary_operator<op, assigned, assigned, assigned>
{
}

class arithmetic_assignment_binop<string op, lang_type assigned, lang_type value, string llvm_function> 
    : binary_operator<op, assigned, value, assigned>
{
  string llvm_function_name = llvm_function;
}

class custom_binop<string op, lang_type lhs, lang_type rhs, lang_type return_type>
    : binary_operator<op, lhs, rhs, return_type>
{
  string codegen;
}

class shift_left_binop<lang_type lhs, lang_type rhs> 
    : custom_binop<"OP_SHL", lhs, rhs, lhs>
{
  let codegen = "return ctx.builder().CreateShl(lhs.get_value(ctx), rhs.get_value(ctx));";
}

class signed_shift_right_binop<lang_type lhs, lang_type rhs> 
    : custom_binop<"OP_SHR", lhs, rhs, lhs>
{
  let codegen = "return ctx.builder().CreateAShr(lhs.get_value(ctx), rhs.get_value(ctx));";
}

class unsigned_shift_right_binop<lang_type lhs, lang_type rhs> 
    : custom_binop<"OP_SHR", lhs, rhs, lhs>
{
  let codegen = "return ctx.builder().CreateLShr(lhs.get_value(ctx), rhs.get_value(ctx));";
}

foreach lhs = [i8, i16, i32, i64, intmax] in {
  def assign_#lhs#_#lhs : trivial_assignment_binop<"OP_ASSIGN", lhs>;
  foreach rhs = [i8, i16, i32, i64, intmax] in {
    if !ge(lhs.width, rhs.width) then {
      def add_assign_#lhs#_#rhs : arithmetic_assignment_binop<"OP_ADD_ASSIGN", lhs, rhs, "CreateAdd">;
      def sub_assign_#lhs#_#rhs : arithmetic_assignment_binop<"OP_SUB_ASSIGN", lhs, rhs, "CreateSub">;
      def mul_assign_#lhs#_#rhs : arithmetic_assignment_binop<"OP_MUL_ASSIGN", lhs, rhs, "CreateMul">;
      def div_assign_#lhs#_#rhs : arithmetic_assignment_binop<"OP_DIV_ASSIGN", lhs, rhs, "CreateSDiv">;
      def mod_assign_#lhs#_#rhs : arithmetic_assignment_binop<"OP_MOD_ASSIGN", lhs, rhs, "CreateSRem">;
      def and_assign_#lhs#_#rhs : arithmetic_assignment_binop<"OP_AND_ASSIGN", lhs, rhs, "CreateAnd">;
      def or_assign_#lhs#_#rhs : arithmetic_assignment_binop<"OP_OR_ASSIGN", lhs, rhs, "CreateOr">;
      def xor_assign_#lhs#_#rhs : arithmetic_assignment_binop<"OP_XOR_ASSIGN", lhs, rhs, "CreateXor">;
    }

    def add_#lhs#_#rhs : arithmetic_binary_operator<"OP_ADD", lhs, rhs, "CreateAdd">;
    def sub_#lhs#_#rhs : arithmetic_binary_operator<"OP_SUB", lhs, rhs, "CreateSub">;
    def mul_#lhs#_#rhs : arithmetic_binary_operator<"OP_MUL", lhs, rhs, "CreateMul">;
    def div_#lhs#_#rhs : arithmetic_binary_operator<"OP_DIV", lhs, rhs, "CreateSDiv">;
    def mod_#lhs#_#rhs : arithmetic_binary_operator<"OP_MOD", lhs, rhs, "CreateSRem">;
    def and_#lhs#_#rhs : arithmetic_binary_operator<"OP_BITWISE_AND", lhs, rhs, "CreateAnd">;
    def or_#lhs#_#rhs : arithmetic_binary_operator<"OP_BITWISE_OR", lhs, rhs, "CreateOr">;
    def xor_#lhs#_#rhs : arithmetic_binary_operator<"OP_BITWISE_XOR", lhs, rhs, "CreateXor">;
    def eq_#lhs#_#rhs : predicate_binary_operator<"OP_EQ", lhs, rhs, "CreateICmpEQ">;
    def neq_#lhs#_#rhs : predicate_binary_operator<"OP_NEQ", lhs, rhs, "CreateICmpNE">;
    def lt_#lhs#_#rhs : predicate_binary_operator<"OP_LESS", lhs, rhs, "CreateICmpSLT">;
    def gt_#lhs#_#rhs : predicate_binary_operator<"OP_GREATER", lhs, rhs, "CreateICmpSGT">;
    def leq_#lhs#_#rhs : predicate_binary_operator<"OP_LEQ", lhs, rhs, "CreateICmpSLE">;
    def geq_#lhs#_#rhs : predicate_binary_operator<"OP_GEQ", lhs, rhs, "CreateICmpSGE">;
  }
}

foreach lhs = [u8, u16, u32, u64, uintmax] in {
  def assign_#lhs : trivial_assignment_binop<"OP_ASSIGN", lhs>;

  // register shifting operators
  foreach rhs = [u8, u16, u32, u64, uintmax] in {
    def shl_#lhs#_#rhs : shift_left_binop<lhs, rhs>;
    def shr_#lhs#_#rhs : unsigned_shift_right_binop<lhs, rhs>;
  }
  foreach rhs = [i8, i16, i32, i64, intmax] in {
    def shr_#lhs#_#rhs : signed_shift_right_binop<lhs, rhs>;
  }

  foreach rhs = [u8, u16, u32, u64, uintmax] in {
    if !ge(lhs.width, rhs.width) then {
      def add_assign_#lhs#_#rhs : arithmetic_assignment_binop<"OP_ADD_ASSIGN", lhs, rhs, "CreateAdd">;
      def sub_assign_#lhs#_#rhs : arithmetic_assignment_binop<"OP_SUB_ASSIGN", lhs, rhs, "CreateSub">;
      def mul_assign_#lhs#_#rhs : arithmetic_assignment_binop<"OP_MUL_ASSIGN", lhs, rhs, "CreateMul">;
      def div_assign_#lhs#_#rhs : arithmetic_assignment_binop<"OP_DIV_ASSIGN", lhs, rhs, "CreateUDiv">;
      def mod_assign_#lhs#_#rhs : arithmetic_assignment_binop<"OP_MOD_ASSIGN", lhs, rhs, "CreateURem">;
      def and_assign_#lhs#_#rhs : arithmetic_assignment_binop<"OP_AND_ASSIGN", lhs, rhs, "CreateAnd">;
      def or_assign_#lhs#_#rhs : arithmetic_assignment_binop<"OP_OR_ASSIGN", lhs, rhs, "CreateOr">;
      def xor_assign_#lhs#_#rhs : arithmetic_assignment_binop<"OP_XOR_ASSIGN", lhs, rhs, "CreateXor">;
    }

    def add_#lhs#_#rhs : arithmetic_binary_operator<"OP_ADD", lhs, rhs, "CreateAdd">;
    def sub_#lhs#_#rhs : arithmetic_binary_operator<"OP_SUB", lhs, rhs, "CreateSub">;
    def mul_#lhs#_#rhs : arithmetic_binary_operator<"OP_MUL", lhs, rhs, "CreateMul">;
    def div_#lhs#_#rhs : arithmetic_binary_operator<"OP_DIV", lhs, rhs, "CreateUDiv">;
    def mod_#lhs#_#rhs : arithmetic_binary_operator<"OP_MOD", lhs, rhs, "CreateURem">;
    def and_#lhs#_#rhs : arithmetic_binary_operator<"OP_BITWISE_AND", lhs, rhs, "CreateAnd">;
    def or_#lhs#_#rhs : arithmetic_binary_operator<"OP_BITWISE_OR", lhs, rhs, "CreateOr">;
    def xor_#lhs#_#rhs : arithmetic_binary_operator<"OP_BITWISE_XOR", lhs, rhs, "CreateXor">;
    def eq_#lhs#_#rhs : predicate_binary_operator<"OP_EQ", lhs, rhs, "CreateICmpEQ">;
    def neq_#lhs#_#rhs : predicate_binary_operator<"OP_NEQ", lhs, rhs, "CreateICmpNE">;
    def lt_#lhs#_#rhs : predicate_binary_operator<"OP_LESS", lhs, rhs, "CreateICmpULT">;
    def gt_#lhs#_#rhs : predicate_binary_operator<"OP_GREATER", lhs, rhs, "CreateICmpUGT">;
    def leq_#lhs#_#rhs : predicate_binary_operator<"OP_LEQ", lhs, rhs, "CreateICmpULE">;
    def geq_#lhs#_#rhs : predicate_binary_operator<"OP_GEQ", lhs, rhs, "CreateICmpUGE">;
  }
}

def land_bool_bool : predicate_binary_operator<"OP_LOGICAL_AND", boolean, boolean, "CreateAnd">;
def lor_bool_bool : predicate_binary_operator<"OP_LOGICAL_OR", boolean, boolean, "CreateOr">;
def assign_bool : trivial_assignment_binop<"OP_ASSIGN", boolean>;

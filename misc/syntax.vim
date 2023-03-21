syn keyword langKeyword auto fn const var consteval comptime using namespace yield return match cast if else while for struct 
syn match langInteger '[0-9]\+'
syn match langInteger '0x[0-9a-f]\+'

syn match langIdentifier '[_a-zA-Z][_a-zA-Z0-9]*'
syn match langLangIdentifier '@[_a-zA-Z][_a-zA-Z0-9]*'
"syn match langOperator '(::|++|--|\.|+|-|!|~|*|&|/|%|<<|>>|<=>|<|<=|>|>=|==|!=|^|||&&||||=|+=|-=|*=|/=|%=|<<=|>>=|&=|^=|\|=|->)'
syn match langParenOpen '('
syn match langParenClose ')'
syn match langBracketOpen '\['
syn match langBracketClose '\]'
syn match langAttrOpen '\[\['
syn match langAttrClose '\]\]'
syn match langBracketOpen '{'
syn match langBracketClose '}'
syn match langSemi ';'
syn match langColon ':'
syn match langComma ','
syn match langBkslash '\\'
"syn match langEllipses '...'

hi link langKeyword Keyword 
hi link langInteger Number 
hi link langIdentifier Identifier
hi langLangIdentifier guifg=#e5c76b

hi link langColon Special

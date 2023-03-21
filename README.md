# lang
|branch   |status|
|---------|------|
|`master` |[![Floweynt](https://circleci.com/gh/Floweynt/lang/tree/master.svg?style=shield )](https://app.circleci.com/pipelines/github/Floweynt/lang?branch=master)|
|`release`|[![Floweynt](https://circleci.com/gh/Floweynt/lang/tree/release.svg?style=shield)](https://app.circleci.com/pipelines/github/Floweynt/lang?branch=release)|
|`dev`    |[![Floweynt](https://circleci.com/gh/Floweynt/lang/tree/dev.svg?style=shield    )](https://app.circleci.com/pipelines/github/Floweynt/lang?branch=dev)|

## build
To build, you need to install:
- `meson`
- `ninja`
- `LLVM-16`

Then you must run the following:

```sh
$ meson setup build
$ cd build
$ ninja
```

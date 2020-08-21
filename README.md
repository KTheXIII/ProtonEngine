# RenderEngine

## Clone repo

```
git clone --recursive https://github.com/KTheXIII/render-engine.git
```

- [RenderEngine](#renderengine)
  - [Clone repo](#clone-repo)
  - [Requirements](#requirements)
  - [Build project](#build-project)
    - [Example for Makefile](#example-for-makefile)
  - [Binary output](#binary-output)

## Requirements

- [premake](https://github.com/premake/premake-core), for building project

## Build project

Look at premake docs [page](https://github.com/premake/premake-core/wiki/Using-Premake) for different builds.

```
premake5 [action]
```

### Example for Makefile

This create `Makefile` project

```
premake5 gmake2
```

Compile

```
make
```

Clean

```
make clean
```

Different config, `release`, `debug` and `dist` are available.

```
make config=debug
```

## Binary output

The binary builds is in bin directory

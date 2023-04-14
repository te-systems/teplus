# TePlus

The Te+ language enables users to write faster and more organized code with an easy and regular syntax, and liberates users by increasing their control over the language.

## Description

-------------


## Installation

First, install the dependencies below, then clone or download the source code of `teplus`.

### Dependencies

- Boost Library `v1.81.0`
- Mingw64 `(gcc v12.2.0)`

---

### Setup

First, change ``BOOST`` directory in `Makefile` with your installed boost path.

```Makefile
BOOST 							= <enter-boost-path>
```
#### Example
```Makefile
BOOST 							= C:/boost
```

---

### Compilation

Enter the ``teplus/Tep`` directory and call the `make instruction`.

```shell
cd ./Tep
make build
```

---

### Test

When `teplus` builded, do some tests below.

```shell
tep --compile --path ./Tests/Project/Source/main.tep
```

If test compilation is finished successfully, call executable `out` program.

If you have done the above steps, the compilation is complete. You can begin to learning `TePlus` language.
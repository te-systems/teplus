# Te+ Layout Standards

## Description

This document declares ``Te+ Layout Standards``. These directives are a guide for programmers and ``Te+ Extension`` developers.

### Contents
- [Internal Command Executor Identifier](#internal-command-executor-identifier)
- [Current/Instant Line Identifier](#currentinstant-line-identifier)
- [Scope Identifier](#scope-identifier)
- [Mid Term Identifier](#mid-term-identifier)
- [Single Line Comment Identifier](#single-line-comment-identifier)
- [Multi Line Comment Identifier](#multi-line-comment-identifier)
- [Preprocessor Identifier](#preprocessor-identifier)
- [Documentation Provider Identifier](#documentation-provider-identifier)
- [Line Ignoring Identifier](#line-ignoring-identifier)


### Internal Command Executor Identifier

``Identifier`` : ``>]``

``Description`` : Executes compiler commands. You can also add commands to the compiler, then run its commands with it.

<br>

``Example``

```tep
>] tep::langmode = example
```

---

### Current/Instant Line Identifier

``Identifier`` : ``o]``

``Description`` : Identifies the current/instant line. Also this represents your current indent.

<br>

``Example``

```tep
o] auto count = 5
```

---

### Scope Identifier

``Identifier(Begin)`` : ``+]``

``Identifier(End)`` : ``-]``

``Description`` : Opens/Closes a new scope. Also this increases/decreases your indent.

<br>

``Example``

```tep
+] if(playerHP <= 0)
o] game.GameOver()
-]
```

---

### Mid Term Identifier

``Identifier`` : ``~]``

``Description`` : Closes the previous scope and creates the new scope. So this creates a new mid scope.

<br>

``Example``

```tep
+] if(batteryStatus.chargePercent <= 5)
o] batteryUI->setStatus(batteryStatus::CRITICAL)

~] else if(batteryStatus.chargePercent <= 20)
o] batteryUI->setStatus(batteryStatus::LOW)

~] else if(batteryStatus.chargePercent <= 100)
o] batteryUI->setStatus(batteryStatus::GOOD)
-]

```

---

### Single Line Comment Identifier

``Identifier`` : ``:]``

``Description`` : Creates a single line comment.

<br>

``Example``

```tep
:] This is a single line comment
```

---

### Multi Line Comment Identifier

``Identifier(Begin)`` : ``:+]``

``Identifier(End)`` : ``:-]``

``Description`` : Creates a multi line comment.

<br>

``Example``

```tep
:+]
    o] This is a multi line comment
    o] ...lorem
    o] ...ipsum
:-]
```

---

### Preprocessor Identifier

``Identifier`` : ``#]``

``Description`` : Used to define the preprocessor.

<br>

``Example``

```tep
#] include <string>
```

---

### Documentation Provider Identifier

``Identifier`` : ``$]``

``Identifier(Begin)`` : ``$+]``

``Identifier(End)`` : ``$-]``

``Description`` : Creates documentation texts.

<br>

``Example``

```tep
$] AssetDatabase::local = "../docs/AssetDatabase"
$] AssetDatabase::link = "https://docs.sitename.com/AssetDatabase"
$] AssetDatabase::desc = "Accessing and performing assets."
o] class AssetDatabase : IDataProvider ...
```

``Example-2``

```tep
$+] AssetDatabase
    o] ::local = "../docs/AssetDatabase"
    o] ::link = "https://docs.sitename.com/AssetDatabase"
    o] ::desc = "Accessing and performing assets."
$-]

o] class AssetDatabase : IDataProvider ...
```

---

### Line Ignoring Identifier

``Identifier`` : ``*]``

``Description`` : Ignores the specified line.

<br>

``Example``

```tep
*] auto maxScore = 130
o] auto maxScore = 210
```

---

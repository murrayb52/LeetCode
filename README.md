# LeetCode

Personal solutions to LeetCode problems, written in C (and occasionally other languages).

## Folder structure

Each problem has its own folder named `<number>_<problemName>/` containing:

- `<number>_<problemName>.c` — the solution (additional languages appear as `<number>_<problemName>.py` etc.)
- `PROBLEM.md` — the original problem statement copied from LeetCode

## Commit conventions

Format: `<prefix>: <number>. <Problem Name> [- <detail>] (<Language>)`

| Prefix | Meaning |
|--------|---------|
| `new` | New solution to a problem (new includes repeating the solution in a different language) |
| `update` | Revision to an existing solution |

- **Problem name**: use the official LeetCode name, title-cased (e.g. `Two Sum`, `Add Two Numbers`)
- **Language**: full name, capitalised (e.g. `C`, `Python`, `Java`)
- **Detail**: optional, only needed for `update` commits to summarise what changed

Examples:
```
new: 1. Two Sum (C)
new: 1. Two Sum (Python)
update: 2. Add Two Numbers - fix carry logic (C)
```

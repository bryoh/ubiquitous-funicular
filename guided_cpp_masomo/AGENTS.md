# Repository Guidelines

## Project Structure & Module Organization
This repository is currently lightweight and documentation-first. The main artifact is [`README.md`](README.md), which captures the C++/Qt learning-program brief and project goals. There is no committed `src/`, `tests/`, or `assets/` tree yet.

When adding implementation files, keep the layout predictable:

- `src/` for application code
- `include/` for public headers
- `tests/` for Google Test suites
- `docs/` for notes, diagrams, and learning material
- `assets/` for sample CSVs, images, and UI resources

Prefer feature-based grouping inside `src/` once the GUI project starts, for example `src/csv/`, `src/charts/`, and `src/ui/`.

## Build, Test, and Development Commands
No build or test commands are wired into the repository yet. If you introduce a CMake-based C++ project, keep the standard flow:

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build
```

Use `cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug` for local debugging. Document any new developer command in `README.md` when you add it.

## Coding Style & Naming Conventions
Follow the Google C++ Style Guide, which is already called out in the project brief. Use 2 or 4 spaces consistently per file, never tabs. Prefer:

- `PascalCase` for types and classes
- `snake_case` for files, variables, and functions where the project standard allows it
- clear module names such as `csv_importer.cpp` or `chart_factory.h`

If you add formatting or linting, use repository-visible tooling such as `clang-format` and commit the config.

## Testing Guidelines
Google Test is the intended test framework. Place tests under `tests/` and name them after the unit under test, for example `tests/csv_importer_test.cpp`. Cover parsing, chart-selection logic, and any design-pattern implementations before adding GUI-heavy tests.

## Commit & Pull Request Guidelines
Recent history shows short, imperative commits and conventional prefixes, such as `feat:`. Prefer concise messages like `feat: add CSV parser skeleton` or `test: add importer edge cases`.

For pull requests:

- explain the change and why it is needed
- link the related issue or learning milestone
- include screenshots for UI work
- note build/test status and any skipped verification

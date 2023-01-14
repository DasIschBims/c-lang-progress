@echo off
for /D %%F in (Day*) do (
    for %%f in ("%%F\*") do (
        if not "%%~xf"=="" (
            if "%%~xf"==".exe" (
                del "%%f"
            )
        ) else (
            del "%%f"
        )
    )
)
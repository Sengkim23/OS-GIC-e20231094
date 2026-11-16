# OS Lab 2 Submission

* Student Name: LY Sengkim
* Student ID: e20231094
* Ubuntu username on the server: gic-ly-sengkim
* My values (`oslab values lab2`): file1 = travel claims.txt, file2 = payroll may.txt, owner = Audit, reader = Engineering, third = Support

## Core 1: Company folders
I used one `mkdir -p` command to create `TechCorp/Audit/archive`, `TechCorp/Engineering`, and `TechCorp/Support`. Then I ran `find TechCorp -type d` to list every folder and check the tree.

## Core 2: Move and copy
I moved `travel claims.txt` from `incoming/` to `reports/` with a relative path, and moved `payroll may.txt` with absolute paths starting with `$OSLAB_WORKSPACE/lab2/`. I copied both reports into `TechCorp/Audit/` with `cp`, so the originals stayed in `reports/`. I also copied the first report into `TechCorp/Audit/archive/` as `first-original.txt`. From inside `TechCorp/Engineering`, I read the Audit copy once with the relative path `../Audit/travel claims.txt` and once with the absolute path.

Decision: For the copy step I used relative paths because they are short and work wherever the lab folder is. An absolute path is better when I run a command from a different folder or in a script, because it always points to the same place.

## Core 3: Proof and path error
I used `cmp` to prove the copies were identical, and it printed nothing. From `TechCorp/Engineering` I ran `cat "reports/travel claims.txt"`, which failed because Engineering has no `reports/` folder inside it. The working path goes up two folders (Engineering, then TechCorp) to reach the lab folder.

Error: cat: 'reports/travel claims.txt': No such file or directory
Fix: ../../reports/travel claims.txt

## What I learned
Names with spaces need quotes, or the shell splits them into separate arguments. A correct file name can still give "No such file or directory" when a relative path starts from the wrong folder.

## Evidence
* evidence/paths.txt
* evidence/tree.txt
* evidence/checkpoint.txt

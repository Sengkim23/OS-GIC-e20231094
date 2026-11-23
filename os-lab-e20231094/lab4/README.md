# Lab 4 — Redirection and Pipelines: Individual Report

## Student Information

- **Name:** LY SENGKIM
- **Student ID:** e20231094
- **Linux account:** gic-ly-sengkim
- **Personal status:** paid
- **Other word:** clear

## Commands I Used

The following commands demonstrate exact matching, field extraction, record counting, and I/O redirection.

| Stage | My command | Input received | Output produced |
|---|---|---|---|
| Select exact first field | `grep '^paid,' data/events.csv \| tee evidence/selected.txt` | `data/events.csv` | Full matching CSV rows |
| Extract field 2 | `grep '^paid,' data/events.csv \| cut -d, -f2 \| tee evidence/fields.txt` | Matching CSV rows | Second-column quantities |
| Count selected records | `grep '^paid,' data/events.csv \| wc -l > evidence/normal.txt` | Matching CSV rows | Record count: 3 |
| Save stdout and stderr separately | `cat data/missing.csv > evidence/stdout.txt 2> evidence/stderr.txt` | Missing input file | Empty stdout and error diagnostic in stderr |
| Save exit status immediately | `echo $? > evidence/status.txt` | Previous command's exit status | Nonzero exit status |

## What My Tests Show

| Test | Expected | Observed result | Mistake it catches |
|---|---|---|---|
| Original records | 3 exact matches | Check `evidence/normal.txt` | Incorrect matching or counting |
| No match | 0 records | Check first line of `evidence/edge.txt` | Incorrect handling of no-match input |
| One added match plus a look-alike | 4 records | Check second line of `evidence/edge.txt` | Prefix matching and counting quantities instead of records |
| Missing input | Empty stdout, diagnostic on stderr, nonzero status | PASS | Confusing normal output with error output |

## Explain the Commands

**1. Why does the comma in `grep '^WORD,'` matter?**

The comma marks the end of the first CSV field. It ensures that only records whose first field exactly matches the requested word are selected. For example, `paid-late` will not match `^paid,`.

**2. Why does `wc -l` count records rather than add quantities?**

`wc -l` counts the number of newline characters (lines) in the selected input. It does not calculate the sum of the second-column quantities. Each matching CSV row represents one record.

**3. Where did you use `>>`, and what would `>` do instead?**

I used `>>` when appending the changed-input count to `evidence/edge.txt`. The first count was saved using `>`. Using `>` again would replace the first count instead of preserving it.

**4. What does `tee` do that `>` alone does not?**

`tee` displays the command's standard output on the terminal and saves the same output to a file. The `>` operator redirects output to a file without displaying it normally.

**5. Why must `echo $?` immediately follow the command being checked?**

`$?` contains the exit status of the most recently executed command. If another command runs first, the previous status is replaced.

**6. Why can `cat missing-file | wc -l` report pipeline status 0?**

The `cat` command fails because the file does not exist, but `wc -l` can still execute successfully and count zero lines. By default, the pipeline reports the exit status of its last command.

## Limits and Evidence

These commands assume simple comma-separated text without quoted commas. The saved evidence represents the results of one execution and does not prove that every possible input will work.

The submission includes:

- `checkpoint.txt`
- `evidence/commands.txt`
- `evidence/selected.txt`
- `evidence/fields.txt`
- `evidence/normal.txt`
- `evidence/edge.txt`
- `evidence/stdout.txt`
- `evidence/stderr.txt`
- `evidence/status.txt`
- `evidence/checkpoint-selected.txt`

No `report.sh` is required.

## Optional Work / AI Note

I reviewed the Linux commands and pipeline concepts with learning assistance. The optional suspicious-client challenge was not completed because its individual dataset was not available in my Ubuntu account.

## Conclusion

This lab helped me understand Linux input and output redirection, standard output, standard error, pipelines, exact text matching, field extraction, and record counting. I also learned how to test missing files and preserve command output using `tee` and append redirection.

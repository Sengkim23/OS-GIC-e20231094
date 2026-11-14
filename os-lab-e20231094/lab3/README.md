# Lab 3 — Wildcards, Hard Links and Symbolic Links: Individual Report

- **Student name/ID:** LY Sengkim / e20231094
- **Ubuntu username:** `gic-ly-sengkim`
- **My values (`oslab values lab3`):** name = candle, tag = final, v1 = 175, v2 = 214
- **Files:** `evidence/wildcards.txt`, `evidence/links.txt`, `evidence/replacement.txt`, `evidence/checkpoint.txt`

## What I Saw

| State | What `cat` printed for the hard link | What `cat` printed for the symbolic link | What `readlink` printed |
|---|---|---|---|
| Before the rename | version 175 | version 175 | candle.txt |
| After the rename, before the repair | version 175 | No such file or directory | candle.txt |
| After a new file took the old name | version 175 | version 214 | candle.txt |
| After my repair | version 175 | version 175 | candle-final.txt |

**My repair (the two commands I wrote):**

```bash
rm candle-soft.txt
ln -s candle-final.txt candle-soft.txt
```

## Explanation

The symbolic link read version 214 after the new file took the old name because it stores a filename, `candle.txt`, rather than the original file's inode. When I created a new file with the same filename, the symbolic link followed that new file. The hard link still referred to the original inode, so it continued to show version 175. In my experiment, the original inode was [INSERT ORIGINAL INODE] and the new file's inode was [INSERT NEW INODE], as shown in `evidence/replacement.txt`.

## What My Tests Do Not Prove

The `cat` command only shows the file contents; it does not prove whether two filenames refer to the same inode. I need to use `ls -li` to compare inode numbers and confirm whether they refer to the same file.

## AI Note (optional)

An AI tool suggested using `ls -li`, `readlink`, and `cat` to test hard links and symbolic links. I used these commands to check the inode numbers, link targets, and file contents.

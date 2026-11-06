import os, subprocess
from PIL import Image, ImageDraw, ImageFont

def sh(cmd):
    try: return subprocess.check_output(cmd, shell=True, text=True, stderr=subprocess.DEVNULL).strip()
    except Exception: return ""

cpu  = sh("grep -m1 'model name' /proc/cpuinfo | cut -d: -f2").strip() or "unknown CPU"
kb   = sh("awk '/MemTotal/ {print $2}' /proc/meminfo")
mem  = f"{int(kb)/1024/1024:.1f} GB" if kb else "unknown"
kern = sh("uname -srm") or "Linux"
mods = sh("lsmod 2>/dev/null | awk 'NR>1{print $1}' | head -3 | paste -sd, - | sed 's/,/, /g'")
if not mods: mods = "(lsmod shows none - add 2-3 module names)"

layers = [
 ("USER SPACE", "#d6e9ff",
  [f"bash shell (PID {os.getppid()})", "Programs: file_creator_sys, file_reader_sys, dir_list_sys",
   "Library versions: file_creator_lib, file_reader_lib, dir_list_lib", "C library (glibc): fopen / printf / fgets"]),
 ("SYSTEM CALL INTERFACE", "#fff2cc",
  ["open()   read()   write()   close()   stat()", "user mode  <->  kernel mode boundary"]),
 ("KERNEL SPACE (Linux, monolithic)", "#e2f0d9",
  [f"Kernel: {kern}", f"Loaded modules: {mods}", "Process mgmt | Memory mgmt | File systems (/proc) | Drivers"]),
 ("HARDWARE", "#f4cccc",
  [f"CPU: {cpu}", f"Memory: {mem}"]),
]

def font(sz, bold=False):
    p = "/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf" if bold else "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf"
    return ImageFont.truetype(p, sz) if os.path.exists(p) else ImageFont.load_default()

W, pad, lh = 1100, 30, 30
heights = [60 + lh*len(l[2]) for l in layers]
H = pad*2 + sum(heights) + 20*(len(layers)-1) + 50
img = Image.new("RGB", (W, H), "white"); d = ImageDraw.Draw(img)
d.text((pad, 15), "OS Layers - my Linux system", fill="black", font=font(24, True))
y = 60
for (title, color, lines), h in zip(layers, heights):
    d.rounded_rectangle([pad, y, W-pad, y+h], 12, fill=color, outline="black", width=2)
    d.text((pad+20, y+12), title, fill="black", font=font(20, True))
    for i, t in enumerate(lines):
        d.text((pad+40, y+48+i*lh), t, fill="black", font=font(18))
    y += h + 20
os.makedirs("screenshots", exist_ok=True)
img.save("screenshots/task4_os_layers_diagram.png")
print("saved screenshots/task4_os_layers_diagram.png")

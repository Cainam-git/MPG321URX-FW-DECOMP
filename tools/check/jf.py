# Check: near.judge pinned to one flag set (argv[4], default -mcpu=v8 -O3 -g)
# usage: jf.py <cpu> <fn> <file.c> [flags] [max diff pairs]
import sys; sys.path.insert(0,'tools'); import near, autoc
fl = sys.argv[4] if len(sys.argv) > 4 else '-mcpu=v8 -O3 -g'
autoc.flag_sets = lambda cpu: [fl]
s,m,why,pairs,flags=near.judge(sys.argv[1],sys.argv[2],sys.argv[3])[:5]
print(f"{s:.2f} match={m} {why} [{flags}]")
for a,b in (pairs or [])[:int(sys.argv[5]) if len(sys.argv)>5 else 30]: print(f"  T: {a:40s} O: {b}")

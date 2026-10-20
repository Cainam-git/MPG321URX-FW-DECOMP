# Check: permuter2.search on a leon2m function with one -O3 flag set pinned (permuter2.py itself picks the best-scoring set)
# usage: p2o3f.py <fn> <draft.c> <out.c> <budget>
import sys, pathlib
sys.path.insert(0, 'tools'); sys.argv = ['permuter2.py', 'leon2m']
import permuter2
src, out, budget = sys.argv_src = None, None, None
src, out, budget = pathlib.Path(sys.orig_argv[-3]), pathlib.Path(sys.orig_argv[-2]), int(sys.orig_argv[-1])
start, best, matched, best_src, n = permuter2.search('leon2m', sys.orig_argv[-4], src, '-mcpu=v8 -O3 -g', budget)
out.write_text(best_src or '')
print(f'{src.name}: {start:.2f} -> {best:.2f} matched={matched} tried={n}', flush=True)

"""Minimal 'toml' module for decomp-permuter (it only reads): backed by the standard tomllib."""
import tomllib
def load(f): return tomllib.loads(f.read() if isinstance(f.read, object) and not isinstance(f, (str, bytes)) else f)
def loads(s): return tomllib.loads(s)

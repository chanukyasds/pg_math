# general config
MODULES = pg_math
EXTENSION = pg_math
DATA = pg_math--1.0.sql

# postgres build config
PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)

LDFLAGS = -lgsl -lgslcblas -lm

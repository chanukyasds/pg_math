#############################
# Makefile for pg_math
#############################

EXTENSION   = pg_math
MODULE_big  = pg_math
OBJS        = pg_math.o
DATA        = pg_math--1.0.sql
PGFILEDESC  = "pg_math - with GNU Scientific Library"

# Homebrew prefix autodetection
BREW_PREFIX := $(shell brew --prefix 2>/dev/null)

# Include and lib paths
PG_CPPFLAGS += -I$(BREW_PREFIX)/include -I$(BREW_PREFIX)/opt/gsl/include
SHLIB_LINK  += -L$(BREW_PREFIX)/lib -L$(BREW_PREFIX)/opt/openblas/lib \
               -Wl,-rpath,$(BREW_PREFIX)/lib -Wl,-rpath,$(BREW_PREFIX)/opt/openblas/lib \
               -lgsl -lgslcblas -lm

# PGXS build (standalone)
PG_CONFIG ?= pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)

SRCDIR := src
INCDIR := include
BUILDDIR := build
OBJDIR := $(BUILDDIR)/obj
DEPDIR := $(BUILDDIR)/deps
TARGETDIR := $(BUILDDIR)/target
BINDIR := bin

SHELL := /usr/bin/env bash
MKDIR := mkdir -p
RM := rm -rf
MV := mv

CXX = g++
CXXFLAGS = -xc++ -Wall -Wextra -std=c++17
LD = g++
LDFLAGS = $(CXXFLAGS)
DEBUGGER = gdb

ifeq ($(RELEASE), 1)
	maketype := release
	CXXFLAGS += -O2 -ftree-vectorize -fomit-frame-pointer -march=native
	# Link Time Optimization
	CXXFLAGS += -flto
else
	maketype := debug
	CXXFLAGS += -Og -ggdb3
	# Overflow protection
	CXXFLAGS += -D_FORTIFY_SOURCE=2 -fstack-protector-strong -fcf-protection \
							-Wl,-z,defs -Wl,-z,now -Wl,-z,relro -D_GLIBCXX_ASSERTIONS
	# Enable only when needed
	CXXFLAGS += -fsanitize=address -fsanitize=undefined -fsanitize=leak
endif

CXXFLAGS += -I$(INCDIR) -MMD -MP

SRCS := $(shell find $(SRCDIR) -regextype posix-extended -regex .*[.]cpp 2>/dev/null)

OBJS := $(foreach obj,$(SRCS),$(OBJDIR)/$(maketype)/$(obj).o)

DEPS := $(foreach dep,$(SRCS),$(DEPDIR)/$(dep).d)

TARGETS := $(foreach target,$(USE_TARGETS),$(TARGETDIR)/$(maketype)/$(target))

.PHONY: all
all : $(TARGETS)

COMPILE = printf "CXX $(maketype) $(2) -> $(1)\n" && \
		$(CXX) -c $(2) -o $(1) -MF $(3) $(CXXFLAGS) $(4)
LINK = printf "LD $(maketype) $(1)\n" && \
		$(LD) -o $(1) $(2) $(LDFLAGS) $(3)

$(TARGETDIR)/$(maketype)/% : $(OBJDIR)/$(maketype)/$(BINDIR)/%.cpp.o $(OBJS)
	@$(MKDIR) "$(@D)"
	-@$(call LINK,$@,$^)

.PHONY: get_target
get_target :
	@printf -- "$(TARGETS)\n"

.PHONY: init
init : clean
	@$(MKDIR) "$(SRCDIR)" "$(INCDIR)" "$(BINDIR)"
	@$(file >compile_flags.txt)
	@$(foreach i,$(CXXFLAGS),$(file >>compile_flags.txt,$(i)))

.PRECIOUS: $(OBJDIR)/$(maketype)/%.o 
$(OBJDIR)/$(maketype)/%.o : %
	@$(eval CUR_DEP := $(DEPDIR)/$<.d)
	@$(MKDIR) "$(@D)" "$(dir $(CUR_DEP))"
	-@$(call COMPILE,$@,$<,$(CUR_DEP))

.PHONY: clean
clean : 
	-$(RM) $(wildcard $(OBJDIR)/$(maketype)/* $(DEPDIR)/* $(TARGETDIR)/$(maketype)/*)

.PHONY: debug
debug : $(TARGETS)
	@export ASAN_OPTIONS=detect_leaks=0; \
		$(DEBUGGER) $(TARGETS)

-include $(DEPS)
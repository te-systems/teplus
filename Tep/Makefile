CPP 							= g++
CPP_FLAGS 						= -g -c -std=c++17 -fdiagnostics-color=always -Wall -pedantic

BOOST 							= C:/boost
BOOST_INCLUDE 					= $(BOOST)/include/boost-1_81
BOOST_LIB 						= $(BOOST)/lib
BOOST_LIBS 						= -lboost_program_options-mgw12-mt-x64-1_81

# == Api Directories == #

API 							= ./API
API_OBJ 						= $(API)/obj
API_BIN 						= $(API)/bin

API_INCLUDE 					= $(API)/include
API_INCLUDE_TEPCORE 			= $(API_INCLUDE)/tepCore
API_INCLUDE_TEPEXTSYS 			= $(API_INCLUDE)/tepExtSys

API_SRC 						= $(API)/src
API_SRC_TEPCORE 				= $(API_SRC)/tepCore
API_SRC_TEPEXTSYS 				= $(API_SRC)/tepExtSys

# ======================== Modules ======================== #

# ==> TEPCORE

LIST_API_TEPCORE = \
	CompileProcess		\
	LayoutCommand		\
	LayoutEvents		\
	LayoutOperation		\
	ProcessEvent		\
	ProcessProperties	\
	ProcessTimer		

INCLUDE_LIST_API_TEPCORE 		= $(foreach file , $(LIST_API_TEPCORE) , $(API_INCLUDE_TEPCORE)/$(file).hpp)
SRC_LIST_API_TEPCORE 			= $(foreach file , $(LIST_API_TEPCORE) , $(API_SRC_TEPCORE)/$(file).cpp)
OBJ_LIST_API_TEPCORE 			= $(foreach file , $(LIST_API_TEPCORE) , $(API_OBJ)/$(file).o)

# ==> TEPEXTSYS

LIST_API_TEPEXTSYS = \
	Extension

INCLUDE_LIST_API_TEPEXTSYS 		= $(foreach file , $(LIST_API_TEPEXTSYS) , $(API_INCLUDE_TEPEXTSYS)/$(file).hpp)
SOURCE_LIST_API_TEPEXTSYS 		= $(foreach file , $(LIST_API_TEPEXTSYS) , $(API_SRC_TEPEXTSYS)/$(file).cpp)
OBJ_LIST_API_TEPEXTSYS 			= $(foreach file , $(LIST_API_TEPEXTSYS) , $(API_OBJ)/$(file).o)


# == Compiler Directories == #

TEP 							= ./Compiler
TEP_INCLUDE 					= $(TEP)/include
TEP_SRC 						= $(TEP)/src
TEP_OBJ 						= $(TEP)/obj
TEP_BIN 						= $(TEP)/bin

# == Recipes == #

define log
	@echo ===============================================================
	@echo $(1)
	@echo ===============================================================
endef

all: build

build: \
	compile_api_core \
	compile_api_extsys \
	compile_api	\
	compile_tep	\
	link_tep	

	$(call log,Compiled.)

compile_out:
	@echo Compiling external...
	g++ out_file.cpp -o out.exe
	@echo Compiled to out.exe

# ===============================================================
compile_api_core : $(OBJ_LIST_API_TEPCORE)

	$(call log,Compiling Module : tepCore)

	$(CPP) $(CPP_FLAGS) \
		-I $(API_INCLUDE) \
		-I $(API_INCLUDE_TEPCORE) \
		-I $(BOOST_INCLUDE) $(API_SRC)/tepCore.cpp \
		-o $(API_OBJ)/tepCore.o

$(OBJ_LIST_API_TEPCORE) : $(LIST_API_TEPCORE)
	
$(LIST_API_TEPCORE) :

	$(call log,Compiling : $@)

	$(CPP) $(CPP_FLAGS) \
		-I $(API_INCLUDE) \
		-I $(API_INCLUDE_TEPCORE) \
		-I $(BOOST_INCLUDE) $(API_SRC_TEPCORE)/$@.cpp \
		-o $(API_OBJ)/$@.o
# ===============================================================
compile_api_extsys : $(OBJ_LIST_API_TEPEXTSYS)

	$(call log,Compiling Module : tepExtSys)

	$(CPP) $(CPP_FLAGS) \
		-I $(API_INCLUDE) \
		-I $(API_INCLUDE_TEPEXTSYS) \
		-I $(BOOST_INCLUDE) $(API_SRC)/tepExtSys.cpp \
		-o $(API_OBJ)/tepExtSys.o

$(OBJ_LIST_API_TEPEXTSYS) : $(LIST_API_TEPEXTSYS)
	
$(LIST_API_TEPEXTSYS) :

	$(call log,Compiling : $@)

	$(CPP) $(CPP_FLAGS) \
		-I $(API_INCLUDE) \
		-I $(API_INCLUDE_TEPEXTSYS) \
		-I $(BOOST_INCLUDE) $(API_SRC_TEPEXTSYS)/$@.cpp \
		-o $(API_OBJ)/$@.o

# ===============================================================

compile_api:

	$(call log,Compiling : tepIO)

	$(CPP) $(CPP_FLAGS) -I $(API_INCLUDE) -I $(BOOST_INCLUDE) $(API_SRC)/tepIO.cpp -o $(API_OBJ)/tepIO.o
# $(CPP) $(CPP_FLAGS) -I $(API_INCLUDE) -I $(BOOST_INCLUDE) $(API_SRC)/tepCore.cpp -o $(API_OBJ)/tepCore.o
# $(CPP) $(CPP_FLAGS) -I $(API_INCLUDE) -I $(BOOST_INCLUDE) $(API_SRC)/tepExtSys.cpp -o $(API_OBJ)/tepExtSys.o

tep: compile_tep link_tep

compile_tep:

	$(call log,Compiling : Tep Compiler)

	$(CPP) $(CPP_FLAGS) \
		-I $(TEP_INCLUDE) \
		-I $(BOOST_INCLUDE) \
		-I $(API_INCLUDE) \
		$(TEP_SRC)/tep.cpp \
		-o $(TEP_OBJ)/tep.o

link_tep:

	$(call log,Linking : Tep Compiler)

	$(CPP) \
		$(TEP_OBJ)/tep.o \
		$(API_OBJ)/tepCore.o \
		$(API_OBJ)/tepIO.o \
		$(OBJ_LIST_API_TEPCORE) \
		-L$(BOOST_LIB) $(BOOST_LIBS) \
		-o tep.exe
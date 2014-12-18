GTEST_DIR  = ./gtest-1.7.0
USER_DIR   = ./src
OUTPUT_DIR = ./output
VPATH      = $(USER_DIR):$(OUTPUT_DIR)

CPPFLAGS += -isystem $(GTEST_DIR)/include
CXXFLAGS += -g -Wall -Wextra -pthread
TESTS     = tiger_blue

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h
all : $(OUTPUT_DIR) $(TESTS)
clean :
	rm -rf $(OUTPUT_DIR)

# GTEST =====
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

gtest-1.7.0.zip :
	wget https://googletest.googlecode.com/files/gtest-1.7.0.zip

$(GTEST_DIR) : gtest-1.7.0.zip
	@test -d $(GTEST_DIR) || unzip $^

#gtest-all.o : $(GTEST_SRCS_) GTEST
gtest-all.o : $(GTEST_DIR)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc \
            -o $(OUTPUT_DIR)/$@
tiger_blue.o : tiger_blue.cpp
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
             $(USER_DIR)/tiger_blue.cpp \
            -o $(OUTPUT_DIR)/$@

# SUT =====
$(OUTPUT_DIR):
	mkdir $(OUTPUT_DIR)
len.o : len.cc len.h 
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/len.cc \
            -o $(OUTPUT_DIR)/$@
len_unittest.o : len_unittest.cc len.h tiger_blue.h $(GTEST_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/len_unittest.cc \
            -o $(OUTPUT_DIR)/$@
# Target =====
tiger_blue : gtest-all.o tiger_blue.o len.o len_unittest.o 
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread \
            $(addprefix $(OUTPUT_DIR)/, len.o len_unittest.o tiger_blue.o gtest-all.o) \
            -o $(OUTPUT_DIR)/$@




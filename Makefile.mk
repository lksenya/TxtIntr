CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic

# Настройки сборки
TARGET = myprogram
SRCS = main.cpp myclass.cpp
OBJS = $(SRCS:.cpp=.o)

# Правило сборки
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Правило компиляции исходных файлов
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Правило очистки
clean:
	rm -f $(OBJS) $(TARGET)

# Nom de l'exécutable
TARGET = jeu

# Compilateur et options
CXX = g++
# On ajoute les flags de wxWidgets demandés par le cours
CXXFLAGS = -Wall -std=c++17 -g `wx-config --cxxflags`

# Les librairies de wxWidgets pour l'édition de liens
LDLIBS = `wx-config --libs`

# Fichiers sources (On n'oublie pas gui.cpp !)
SRCS = main.cpp Grille.cpp Jeu.cpp gui.cpp

# Fichiers objets
OBJS = $(SRCS:.cpp=.o)

# Règle par défaut
all: $(TARGET)

# Comment construire l'exécutable (ajout de $(LDLIBS) à la fin)
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LDLIBS)

# Comment compiler un .cpp en .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage
clean:
	rm -f $(OBJS) $(TARGET)
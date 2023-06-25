# Compilateur
CXX = g++

# Options de compilation
CXXFLAGS = -std=c++11 -Wall

# Chemins d'inclusion des en-têtes SFML
SFML_INCLUDE = -I/home/marsouin/Téléchargements/SFML-2.6.0/include

# Chemins des bibliothèques SFML
SFML_LIBS = -L/home/marsouin/Téléchargements/SFML-2.6.0/lib -lsfml-graphics -lsfml-window -lsfml-system

# Nom du programme de sortie
TARGET = pokemon_platine

# Liste des fichiers source
SOURCES = main.cpp

# Export de LD_LIBRARY_PATH
export LD_LIBRARY_PATH := /home/marsouin/Téléchargements/SFML-2.6.0/lib:$(LD_LIBRARY_PATH)

# Génération de la cible par défaut
all: $(TARGET)

# Règle pour la cible
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) $^ -o $@ $(SFML_LIBS)

# Règle pour exécuter le programme en spécifiant le chemin des bibliothèques SFML
run: $(TARGET)
	LD_LIBRARY_PATH=/home/marsouin/Téléchargements/SFML-2.6.0/lib ./$(TARGET)

# Règle pour nettoyer les fichiers objets et le programme
clean:
	rm -f $(TARGET)

.PHONY: all clean

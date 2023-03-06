import numpy as np

# 1. Transformer les deux matrices M1 et M2 en tableaux
M1 = np.array([[1,2,3], [0,1,2], [0,4,6]])
M2 = np.array([[2,4,1], [2,5,1], [1,2,1]])

# 2. Calculer et afficher la somme des deux matrice M1 et M2
somme = M1 + M2
print(somme)

# 3. Calculer et afficher la soustraction des deux matrice M1 et M2
soustraction = M1 - M2
print(soustraction)

# 4. Calculer et afficher la multiplication des deux matrice M1 et M2
multiplication = M1.dot(M2)
print(multiplication)

# 5. Calculer et afficher la multiplication de M1 par 3
M3 = 3*M1
# autres methodes:
# M3 = M1.dot(3)
# M3 = np.dot(M1, 3)
print(M3)

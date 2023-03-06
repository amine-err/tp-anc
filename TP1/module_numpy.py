import numpy as np

# 1. Créer un tableau de 2 dimension
my_2d_table = np.array([[1, 2, 3], [4, 5, 6]])

# 2. Afficher le tableau my_2d_table
print(my_2d_table)

# 3. Afficher la dimension du tableau my_2d_table
print(my_2d_table.ndim)

# 4. Afficher la forme du tableau my_2d_table
print(my_2d_table.shape)

# 5. Afficher le nombre d’éléments du tableau my_2d_table
print(my_2d_table.size)

# 6. Créer un deuxième tableau de 2 dimension
my_2d_ones = np.ones((2, 2))

# 7. Afficher le tableau my_2d_ones
print(my_2d_ones)

# 8. Créer un nouveau tableau my_concat_table qui concatène horizontalement
# les deux tableaux : my_2d_table et my_2d_ones
my_concat_table = np.concatenate((my_2d_table, my_2d_ones), axis=1)
# autre methode:
# my_concat_table = np.hstack((my_2d_table, my_2d_ones))

# 9. Afficher la dimension du tableau my_concat_table
print(my_concat_table.ndim)

# 10.Afficher la forme du tableau my_concat_table
print(my_concat_table.shape)

# 11.Afficher le nombre d’éléments du tableau my_concat_table
print(my_concat_table.size)

# 12.Aplatir le tableau my_concat_table, et puis afficher sa nouvelle forme
my_concat_table = my_concat_table.ravel()
print(my_concat_table.shape)

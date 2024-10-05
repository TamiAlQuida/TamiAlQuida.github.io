
true_matrix = [[1,2,3,4], 
               [2,4,1,3], 
               [3,1,4,2], 
               [4,3,2,1]]
false_matrix = [[1,2,3], [3,2,1], [1,3,2]]



def check_numeric_matrix(matrix):
    sum_row = 0
    sum_column = 0

    for i in range(len(matrix)):
        print(matrix[i])
        row = 0
        column = 0
        for j in range(len(matrix)):
            row += matrix[i][j]
            column += matrix[j][i]

        print('row', row)
        print('column', column)

        if (row == sum_row == column == sum_column) or (sum_row == 0 == sum_column):
            print('success')

        else:
            print('failed')
        
        sum_row = row
        sum_column = column


check_numeric_matrix(true_matrix)
check_numeric_matrix(false_matrix)


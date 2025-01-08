import matplotlib.pyplot as plt

def draw_line_segments(points):

    for i in range(len(points) - 1):
        point1 = points[i]
        point2 = points[i + 1]
        x_values = [point1[0], point2[0]]
        y_values = [point1[1], point2[1]]

        plt.plot(x_values, y_values)

    plt.grid(True)
    plt.legend()
    plt.show()

points = [ (0, 0), (2, 4), (4, 0),(0,0)]
draw_line_segments(points)

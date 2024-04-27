#include <stdio.h>
#include <stdlib.h>


// Definindo uma estrutura para representar um ponto no plano cartesiano
typedef struct {
    float X; 
    float Y; 
} Point;

// Estrutura para representar um poligono
typedef struct {
    int numVertices; 
    Point *vertices; 
} Polygon;

// Função para calcular a área de um triângulo dado três pontos
float TriangleArea(Point A, Point B, Point C) {
    //formula do determinante
    float determinant = (A.X * B.Y + B.X * C.Y + C.X * A.Y) - (A.Y * B.X + B.Y * C.X + C.Y * A.X);
    return fabs(determinant) / 2.0;
}

// Função para calcular a área de um poligono dado seus vértices
float PolygonArea(Polygon polygon) {
    float area = 0.0; 


    // Calcula-se a área de cada triângulo e soma-se à área total do polígono
    for (int i = 1; i < polygon.numVertices - 1; i++) {
        area += TriangleArea(polygon.vertices[0], polygon.vertices[i], polygon.vertices[i + 1]);
    }

    return area; // Retornar a área total do polígono
}

int main() {
    system("cls");
    FILE *file; 
    int numVertices; 
    Point *vertices; 
    Polygon polygon; 

    // Abre o arquivo para leitura
    file = fopen("coordenadas.txt", "r"); 
    if (file == NULL) { 
        printf("Erro ao abrir o arquivo.\n");
        return 1; 
    }

    fscanf(file, "%d", &numVertices); 

    vertices = (Point*)malloc(numVertices * sizeof(Point)); 

    // Ler os vertices do poligono do arquivo e armazena no array
    for (int i = 0; i < numVertices; i++) {
        fscanf(file, "%f %f", &vertices[i].X, &vertices[i].Y);
    }

    fclose(file); 

    polygon.numVertices = numVertices; 
    polygon.vertices = vertices;

    // Calcular e imprimir a área do polígono
    printf("A area do poligono e: %.2f\n", PolygonArea(polygon));

    free(vertices); 

    return 0; 
}

#include <iostream>
#include <cmath>
#include <vector>
#include <utility>

using namespace std;

// Fonction pour calculer les points d'intersection de deux cercles
vector<pair<double, double>> findIntersections(double xA, double yA, double rA, double xB, double yB, double rB) {
    vector<pair<double, double>> intersections;

    // Calculer la distance entre les centres des cercles
    double d = sqrt(pow(xB - xA, 2) + pow(yB - yA, 2));

    // Vérifier si les cercles se croisent
    if (d > rA + rB || d < abs(rA - rB)) {
        // Pas d'intersection
        return intersections;
    }

    // Calcul des points d'intersection
    double a = (pow(rA, 2) - pow(rB, 2) + pow(d, 2)) / (2 * d);
    double h = sqrt(pow(rA, 2) - pow(a, 2));

    // Point P0, le point sur la ligne entre les centres
    double Px = xA + a * (xB - xA) / d;
    double Py = yA + a * (yB - yA) / d;

    // Points d'intersection
    double intersection1_x = Px + h * (yB - yA) / d;
    double intersection1_y = Py - h * (xB - xA) / d;

    double intersection2_x = Px - h * (yB - yA) / d;
    double intersection2_y = Py + h * (xB - xA) / d;

    intersections.push_back(make_pair(intersection1_x, intersection1_y));
    intersections.push_back(make_pair(intersection2_x, intersection2_y));

    return intersections;
}

int main() {
    // Positions des points de référence
    double xA = 0, yA = 0 ; // Point A
    
    double xB = 4, yB = 0; // Point B

    // Distances mesurées
    double dA = 3 ; // Distance du point A
    double dB = 3; // Distance du point B

    // Calculer les intersections
    vector<pair<double, double>> intersections = findIntersections(xA, yA, dA, xB, yB, dB);

    // Afficher les résultats
    if (intersections.empty()) {
        cout << "Pas d'intersection trouvée." << endl;
    }
    else {
        cout << "Points d'intersection : " << endl;
        for (const auto& point : intersections) {
            cout << "(" << point.first << ", " << point.second << ")" << endl;
        }
    }

    return 0;
}

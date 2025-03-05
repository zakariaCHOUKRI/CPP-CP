#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define sor3a ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

double getAngle(int p1x, int p1y, int p2x, int p2y, int p3x, int p3y) {
    // Vectors from p2 to p1 and p2 to p3
    double v1x = p1x - p2x;
    double v1y = p1y - p2y;
    double v2x = p3x - p2x;
    double v2y = p3y - p2y;

    // Dot product of vectors
    double dotProduct = v1x * v2x + v1y * v2y;

    // Magnitudes of the vectors
    double magnitudeV1 = sqrt(v1x * v1x + v1y * v1y);
    double magnitudeV2 = sqrt(v2x * v2x + v2y * v2y);

    // Calculate the cosine of the angle
    double cosTheta = dotProduct / (magnitudeV1 * magnitudeV2);

    // Clamp the value to [-1, 1] to avoid numerical issues
    cosTheta = max(-1.0, min(1.0, cosTheta));

    // Calculate the angle in radians
    double angleRad = acos(cosTheta);

    // Convert to degrees
    double angleDeg = angleRad * (180.0 / M_PI);

    // Return the smallest angle
    return angleDeg;
}


int main() {

    sor3a

    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    cout << getAngle(a, b, c, d, e, f) << endl;


    return 0;
}
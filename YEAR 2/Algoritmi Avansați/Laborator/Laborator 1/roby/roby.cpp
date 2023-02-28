#include <iostream>
using namespace std;

int N;
long long delta;
int v_left, v_right, v_touch;

int main()
{
    cin>>N;

    // PAS DE PORNIRE - P1, P2
    int xp, yp, xq, yq, xr, yr;
    cin>>xp>>yp>>xq>>yq;

    // RETINEM INDICII PENTRU VIRAJUL DE INTOARCERE
    int x1 = xp, y1 = yp;

    for (int i = 2; i < N; i++)
    {
        cin>>xr>>yr;

        // CALCUL DETERMINANT
        delta = xq*yr + xr*yp + xp*yq - xq*yp - xr*yq - xp*yr;

        // LEFT, RIGHT, TOUCH
        if (delta == 0) v_touch++;
        else if (delta < 0) v_right++;
            else v_left++;

        // ACTUALIZARE xp, yp, xq, yq
        xp = xq, yp = yq, xq = xr, yq = yr;
    }

    // VIRAJ DE INTOARCERE
    xr = x1, yr = y1;

    // CALCUL DETERMINANT
    delta = xq*yr + xr*yp + xp*yq - xq*yp - xr*yq - xp*yr;

    // LEFT, RIGHT, TOUCH
    if (delta == 0) v_touch++;
    else if (delta < 0) v_right++;
        else v_left++;

    cout<<v_left<<' '<<v_right<<' '<<v_touch;
}
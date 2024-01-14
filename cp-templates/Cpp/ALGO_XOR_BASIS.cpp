const ll bitmax = 64, one = 1;
vector<ll> basis(bitmax, 0); // basis
void insertVector(ll mask)
{
    for (int i = bitmax - 1; i >= 0; i--)
    {
        if ((mask & (one << i)) == 0)
            continue; // continue if i != f(mask)

        if (!basis[i])
        { // If there is no basis vector with the i'th bit set, then insert this vector into the basis
            basis[i] = mask;
            return;
        }
        mask ^= basis[i]; // Otherwise subtract the basis vector from this vector
    }
}

// MAX SUBSET XOR
// ll ans = 0;
// for (int i = bitmax - 1; i >= 0; i--)
// {
//     if (!basis[i])
//         continue;
//     if (ans & one << i)
//         continue;
//     ans ^= basis[i];
// }
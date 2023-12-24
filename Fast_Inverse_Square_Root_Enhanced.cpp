double Q_rsqrt( double number ){
    long long i;                                           // 64-bit integer
    double y;                                              // 64-bit double
    const double three = 3.0F;

    y = number;
    i = * ( long long * ) &y;                              // evil floating point bit level hacking
    i = 0x5FE6EB50C0000000 - ( i >> 1 );                   // what the fuck?
    y = * ( double * ) &i;

    y = y * (number * y * y + three)/(three * number * y * y + 1);  // 1st iteration
    y = y * (number * y * y + three)/(three * number * y * y + 1);  // 2nd iteration
//  y = y * (number * y * y + three)/(three * number * y * y + 1);  // 3rd iteration
//  y = y * (number * y * y + three)/(three * number * y * y + 1);  // 4th iteration, more iterations more accuracy

    return y;
}
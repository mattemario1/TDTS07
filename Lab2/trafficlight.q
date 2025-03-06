//This file was generated from UPPAAL 4.0.6 (rev. 2987), March 2007

/*
Lights on perpendicular directions must not simultaneously be green
*/
A<> not ((N_trafficlight or S_trafficlight) and (W_trafficlight or E_trafficlight))

/*

*/
E<> (N_trafficlight and N_sensor)

/*

*/
E<> (S_trafficlight and S_sensor)

/*

*/
E<> (E_trafficlight and E_sensor)

/*

*/
E<> (W_trafficlight and W_sensor)

/*

*/
A<> N_sensor

/*

*/
A<> S_sensor

/*

*/
A<> E_sensor

/*

*/
A<> W_sensor

/*

*/
//NO_QUERY

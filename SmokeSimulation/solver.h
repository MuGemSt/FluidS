#pragma once

#define IX(i,j) ((i)+(N+2)*(j))
#define SWAP(x0,x) {float * tmp=x0;x0=x;x=tmp;}
#define FOR_EACH_CELL for ( i=1 ; i<=N ; i++ ) { for ( j=1 ; j<=N ; j++ ) {
#define END_FOR }}

class solver
{
public:
	solver(void);
	~solver(void);

	void add_source ( int N, float * x, float * s, float dt );
	void set_bnd ( int N, int b, float * x );
	void lin_solve ( int N, int b, float * x, float * x0, float a, float c );
	void diffuse ( int N, int b, float * x, float * x0, float diff, float dt );
	void advect ( int N, int b, float * d, float * d0, float * u, float * v, float dt );
	void project ( int N, float * u, float * v, float * p, float * div );
	void dens_step ( int N, float * x, float * x0, float * u, float * v, float diff, float dt );
	void vel_step ( int N, float * u, float * v, float * u0, float * v0, float visc, float dt );


};

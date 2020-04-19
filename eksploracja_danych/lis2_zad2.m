d=100; N=1000;M=1000;

X = rand(d,N);
Y = rand(d,M);

function dist = dist_m(X,Y)
	dist = sqrt((sum(X.**2)') .+ (sum(Y.**2)) .+ (-2 .* X' * Y));
end%(sqrt((x-y)^2)

tic;
dist_m(X,Y);
toc;


d=100; N=10000;M=1000;

X = rand(d,N);
Y = rand(d,M);


tic;
dist_m(X,Y);
toc;




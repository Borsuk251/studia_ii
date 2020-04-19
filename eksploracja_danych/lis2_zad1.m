%lista1 zadanie1
%a

d=100
x = rand(d,1);
y = rand(d,1);
w = rand(d,1);

function len1 = length(x)
	len1 = sqrt(sum(x'*x));
end

function mean_w = mean_w(x,w)
	mean_w = sum(x'*w)/sum(w);
end

length(x)
mean_w(x,w)
length(x-y) %length of x-y
x'*y %dot product

%b
d1 = 3; N=10;
X = rand(d1,N);
y1 = rand(d1,1);
w1 = rand(d1,1);

function len_m = len_m(X)
	len_m = sqrt(sum(X.**2,1));
end

function mean_m(X,w)
	mean_m = sum(X.*w)/sum(w);
end

function dist = dist_eu(X,y)
	dist = sqrt(sum((X.-y).**2,1));
end

function sc = scalar_pr(X,y)
	sc = sum(X.*y,1)
end

len_m(X)
mean_w(X,w1)
dist_eu(X,y1)
scalar_pr(X,y1)

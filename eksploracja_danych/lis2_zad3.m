d=100; N=1000;M=1500;

X = rand(d,N);
Y = rand(d,M);


function indices = neigh(X,Y)
	[neigh, indices] = min((sum(X.**2)') .+ (sum(Y.**2)) .+ (-2 .* X' * Y));
end

tic;
neigh(X,Y);
toc;


function indices = Kneigh(X,Y,k)
		[neigh, ind] = sort((sum(X.**2)') .+ (sum(Y.**2)) .+ (-2 .* X' * Y));
		 indices = ind(1:k,:);
end

function A = Kneigh2(X,Y,k) %poprawa bez sortowania
	%[neigh, indices] = (sum(X.**2)') .+ (sum(Y.**2)) .+ (-2 .* X' * Y);
	A=[]
	for i = 1:k
		[neigh, indices] = min((sum(X.**2)') .+ (sum(Y.**2)) .+ (-2 .* X' * Y));
		A=[A;indices]
		Y(:,indices)=[]
	end
	
end


tic;
Kneigh(X,Y,2);
toc;

%Oskar Bujacz
%zadanie0 lista2 matlab

% nazwy wektorow i macierzy odpowiadaja podpunktom zadania

a = [1:100];
b= [1:2:99];
c = pi*[(-1):0.01:1]
%size(c)

d = nonzeros(c');

e1 = sin(1:100);
e2 = zeros(1,100);
e3 = max(e1,e2);

A = reshape(1:100,10,10);
B1 = diag(1:100);
B2 = diag(99:-1:1, 1);
B3 = diag(99:-1:1, -1);
B = B1+B2+B3;
C = triu(ones(10,10));
D1 = 1:100;
D2 =[cumsum(D1),cumprod(D1)];
D = reshape(D2,2,100);

E = zeros(100,100);
for i = 1:100
	for j = 1:100
		if mod(j,i)==0
			E(i,j)=1;
		end
	end
end
%disp(E);



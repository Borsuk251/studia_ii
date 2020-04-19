n = 10000;
stay=0;
change=0;
tic;
for i = 1:n
	prize = randi(3);%nagroda
	choice = randi(3);%wybor
	if choice==prize
		stay+=1;
	end
	if choice!=prize
		change+=1;
	end
end
toc;
fprintf("stay = %d\n", stay/n)
fprintf("change = %d\n", change/n)

%dla 10kk for 1200s, matrix <1s
r=100000000%duzo szybciej
tic;
K = randi([1 3],[2 r]);

B = diff(K);
sB = numel(B)
nzeros=sB-nnz(B);
fprintf("stay = %d\n", nzeros/r)
fprintf("change = %d\n", (sB-nzeros)/r)
toc;

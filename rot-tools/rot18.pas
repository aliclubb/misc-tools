program ROT18;

var
	c:char;
	t, p:integer;
	i:array[1..1024] of integer;

begin
	p := 0;
	repeat
	p := p + 1;
	read(c);
	i[p] := ord(c);
	until i[p] = 10;
	p := 1;
	repeat
	if (i[p] <> 10) then begin
		if ((i[p] >= 78) and (i[p] < 92)) or (i[p] >= 110) then begin
			t := 0;
			while ((i[p] >= 78) and (i[p] < 92)) or (i[p] >= 110) do begin
				i[p] := i[p] - 1;
				t := t + 1;
			end;
			if (i[p] > 92) then
				write(chr(96 + t))
			else
				write(chr(64 + t))
		end
			else if ((i[p] <> 32) and (i[p] > 60)) then
				write(chr(i[p] + 13))
			else if (i[p] = 32) then
				write(chr(i[p]))
			else if (i[p] >= 53) then begin
				t := 0;
				while (i[p] >= 54) do begin
					t := t + 1;
					i[p] := i[p] - 1;
				end;
				write(chr(48 + t));
				end
				else
					write(chr(i[p] + 5));
				end;
	p := p + 1;
	until i[p] = 10;
	write(chr(10));
end.
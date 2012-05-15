c = Array.new(1024)
i = 1
c[i] = STDIN.getc
begin
  i = i + 1
  c[i] = STDIN.getc
end while c[i] > 10
i = 1
begin
  if (c[i] >= 78 and c[i] < 92) or (c[i] >= 110)
    t = 0
    while (c[i] >= 78 and c[i] < 92) or (c[i] >= 110)
      c[i] = c[i] - 1
      t = t + 1
    end
    if c[i] > 92
      putc 96 + t
    else
      putc 64 + t
    end
  else if (c[i] != 32 and c[i] > 60)
    putc c[i] + 13
  else if c[i] == 32
    putc c[i]
  else if c[i] >= 53
    begin
      t = 0
      while c[i] >= 54
        c[i] = c[i] - 1
        t = t + 1
      end
      putc t + 48
    end
  else
    putc c[i] + 5
  end
end
end
end
  i = i + 1
end until c[i] == 10
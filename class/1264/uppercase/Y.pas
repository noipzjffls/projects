(*
User: shenyouran
Problem: 1336
Algorithm: DFS
Language: Pascal
Record ID: 74615
Submit Time: 2020-10-18 10:15:07
*)
var
    v,g,i,j:integer;
    a:array[1..25] of integer;
    b:array[1..15,1..25] of integer;
    id:array[1..15] of integer;
    f:array[1..15] of boolean;
procedure dfs(k,x:integer);
    var
        i:integer;
        c:array[1..25] of longint;
    begin
        if k>x then
            begin
                fillchar(c,sizeof(c),0);
                for i:=1 to x do for j:=1 to v do inc(c[j],b[id[i]][j]);
                for i:=1 to v do if a[i]>c[i] then exit;
                write(x,' ');
                for i:=1 to x do write(id[i],' ');
                halt;
            end;
        for i:=id[k-1]+1 to g do
            begin
                if f[i] then continue;
                id[k]:=i;
                f[i]:=true;
                dfs(k+1,x);
                f[i]:=false;
            end;
    end;
begin
    read(v);
    for i:=1 to v do read(a[i]);
    read(g);
    for i:=1 to g do for j:=1 to v do read(b[i][j]);
    for i:=1 to g do
        begin
            for j:=1 to v do
                begin
                    fillchar(id,sizeof(id),0);
                    fillchar(f,sizeof(f),false);
                    dfs(1,i);
                end;
        end;
end.
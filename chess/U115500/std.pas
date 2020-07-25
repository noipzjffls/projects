var
    n,kingx,kingy,i,j:integer;
    king,ch:char;
    attack:array[0..6] of integer;
    board:array[0..9,0..9] of char;
    names:array[0..6] of char;
function t(ch:char):integer;
    begin
        ch:=lowercase(ch);
        if ch='r' then exit(1);
        if ch='b' then exit(2);
        if ch='q' then exit(3);
        if ch='n' then exit(4);
        if ch='p' then exit(5);
        exit(0);
    end;
function isupper(ch:char):boolean;
    begin
        exit((ord(ch)>64) and (ord(ch)<91));
    end;
function islower(ch:char):boolean;
    begin
        exit((ord(ch)>96) and (ord(ch)<123));
    end;
function isalpha(ch:char):boolean;
    begin
        exit(isupper(ch) or islower(ch));
    end;
function pawn(x,y:integer):boolean;
    begin
        exit(((king='K') and ((board[x+1][y-1]='K') or (board[x+1][y+1]='K'))) or ((king='k') and ((board[x-1][y-1]='k') or (board[x-1][y+1]='k'))));
    end;
function rook(x,y:integer):boolean;
    var nx:integer;
    begin
        if (kingx<>x) and (kingy<>y) then exit(false);
        nx:=x;
        while nx<9 do
            begin
                inc(nx);
                if nx=kingx then exit(true);
                if board[nx][y]<>'*' then break;
            end;
        nx:=y;
        while nx<9 do
            begin
                inc(nx);
                if nx=kingy then exit(true);
                if board[x][nx]<>'*' then break;
            end;
        nx:=x;
        while nx>0 do
            begin
                dec(nx);
                if nx=kingx then exit(true);
                if board[nx][y]<>'*' then break;
            end;
        nx:=y;
        while nx>0 do
            begin
                dec(nx);
                if nx=kingy then exit(true);
                if board[x][nx]<>'*' then break;
            end;
        exit(false);
    end;
function bishop(x,y:integer):boolean;
    var nx,ny:integer;
    begin
        nx:=x;
        ny:=y;
        while (nx>0) and (ny>0) do
            begin
                dec(nx);
                dec(ny);
                if ((nx=kingx) and (ny=kingy)) then exit(true);
                if board[nx][ny]<>'*' then break;
            end;
        nx:=x;
        ny:=y;
        while (nx<9) and (ny>0) do
            begin
                inc(nx);
                dec(ny);
                if ((nx=kingx) and (ny=kingy)) then exit(true);
                if board[nx][ny]<>'*' then break;
            end;
        nx:=x;
        ny:=y;
        while (nx>0) and (ny<9) do
            begin
                dec(nx);
                inc(ny);
                if (nx=kingx) and (ny=kingy) then exit(true);
                if board[nx][ny]<>'*' then break;
            end;
        nx:=x;
        ny:=y;
        while (nx<9) and (ny<9) do
            begin
                inc(nx);
                inc(ny);
                if (nx=kingx) and (ny=kingy) then exit(true);
                if board[nx][ny]<>'*' then break;
            end;
        exit(false);
    end;
function queen(x,y:integer):boolean;
    begin
        exit(rook(x,y) or bishop(x,y));
    end;
function knight(x,y:integer):boolean;
    var i,nx,ny:integer;
    const
        dx:array[0..7] of integer=(-2,-2,-1,-1,1,1,2,2);
        dy:array[0..7] of integer=(-1,1,-2,2,-2,2,-1,1);
    begin
        for i:=0 to 7 do
            begin
                nx:=x+dx[i];
                ny:=y+dy[i];
                if (nx=kingx) and (ny=kingy) then exit(true);
            end;
        exit(false);
    end;
function check(x,y,z:integer):boolean;
    begin
        if z=1 then exit(rook(x,y));
        if z=2 then exit(bishop(x,y));
        if z=3 then exit(queen(x,y));
        if z=4 then exit(knight(x,y));
        if z=5 then exit(pawn(x,y));
        exit(false);
    end;
begin
    fillchar(attack,sizeof(attack),0);
    readln(n);
    for i:=1 to 8 do
        begin
            for j:=1 to 8 do
                begin
                    read(board[i][j]);
                    if (board[i][j]='K') or (board[i][j]='k') then
                        begin
                            king:=board[i][j];
                            kingx:=i;
                            kingy:=j;
                        end;
                end;
        read(ch);
        end;
    if isupper(king) then
        begin
            names[1]:='r';
            names[2]:='b';
            names[3]:='q';
            names[4]:='n';
            names[5]:='p';
        end
    else
        begin
            names[1]:='R';
            names[2]:='B';
            names[3]:='Q';
            names[4]:='N';
            names[5]:='P';
        end;
    for i:=1 to 8 do
        for j:=1 to 8 do
            begin
                if (isalpha(board[i][j])) and (isupper(board[i][j])=islower(king)) and check(i,j,t(board[i][j])) then
                    inc(attack[t(board[i][j])]);
            end;
    for i:=1 to 5 do
        for j:=1 to attack[i] do
            writeln(names[i],'+');
end.
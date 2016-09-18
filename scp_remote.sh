#!/bin/bash
#!/usr/bin/expect -f

# connect via scp
ln=$(cat IPListfile.txt | grep $1 | awk '{print}');
board=($ln);
ip=${board[0]};
fpath=${board[1]};
echo "SCP into $ip";
scp -r build ubuntu@${ip}:$fpath

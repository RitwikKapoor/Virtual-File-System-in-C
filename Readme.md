Run the following commands

sudo apt-get install libncurses5-dev libncursesw5-dev(to install fuse)

./build.sh (to make executable file by name of a.out)

mkdir mnt (to make the directory where we can mount our file system)

./a.out mnt (for mounting)
 ./a.out -f -s -d mnt (to see more info about inodes and mounting)


mount | less (Scroll at the bottom to check if your file system is mounted)

Now you can 'cd mnt' and see everything

fusermount -u mnt (for unmounting the file system)


Some files that helped in creating the program:-

man 2 stat
man inode
less /usr/include/fuse/fuse.h



#ifndef FUSE_USE_VERSION
#define FUSE_USE_VERSION 30
#endif

#include<fuse.h>
#include<stdio.h>
#include<string.h>
#include<errno.h>

//#define PASSWORD "abc123#"

static struct stat regular_file = {
	.st_mode = S_IFREG | 00400,
};

int fuse_read(const char *path, char *data, size_t size, off_t offset,
                     struct fuse_file_info *finfo){
	
	if(strcmp(path, "/my_file") == 0){
		strcpy(data, "Hello World!\n");
		return strlen("Hello World\n");
	}
	return -ENOENT;
}

int fuse_readdir(const char *path, void *buf, fuse_fill_dir_t filler, off_t offset,
                        struct fuse_file_info *fi){
	if(!strcmp(path, "/")){
		filler(buf, "my_file", &regular_file, 0);
	}	
	return 0;
}

int fuse_getattr(const char * path, struct stat * stbuf){
	int res = 0;
	memset(stbuf, 0, sizeof(struct stat));

	if(strcmp(path, "/") == 0){
		stbuf->st_mode = S_IFDIR | 00400;
		stbuf->st_nlink = 2;
	}
	if(strcmp(path, "/my_file") == 0){
		stbuf->st_mode = regular_file.st_mode;
		stbuf->st_size = strlen("Hello World\n");
	}
	
	return res;
}


static struct fuse_operations myOperations = {
	.getattr = fuse_getattr,
	.read = fuse_read,
	.readdir = fuse_readdir,
};


int main(int argc, char* argv[]){
	return fuse_main(argc, argv, &myOperations, 0);
}

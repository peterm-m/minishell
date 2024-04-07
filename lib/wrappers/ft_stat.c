/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:23:43 by pedromar          #+#    #+#             */
/*   Updated: 2024/02/29 20:24:32 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrappers.h"

void	ft_stat(const char *filename, struct stat *buf)
{
	if (stat(filename, buf) < 0)
		unix_error("Stat error");
}

/*
	obtains information about the file pointed to by filepath.

	The buf argument is a pointer to a stat structure and into which
	information is placed concerning the file.

	    struct stat { 
             dev_t    st_dev;    // device inode resides on
             ino_t    st_ino;    // inode's number
             mode_t   st_mode;   // inode protection mode
             nlink_t  st_nlink;  // number of hard links to the file
             uid_t    st_uid;    // user-id of owner
             gid_t    st_gid;    // group-id of owner
             dev_t    st_rdev;   // device type, for special file inode
             struct timespec st_atimespec;  // time of last access
             struct timespec st_mtimespec;  // time of last data modification
             struct timespec st_ctimespec;  // time of last file status change
             off_t    st_size;   // file size, in bytes
             quad_t   st_blocks; // blocks allocated for file
             u_long   st_blksize;// optimal file sys I/O ops blocksize
             u_long   st_flags;  // user defined flags for file
             u_long   st_gen;    // file generation number
        };

	st_atime         Time when file data last accessed.
	st_mtime         Time when file data last modified
	st_ctime         Time when file status was last changed
	st_birthtime     Time of file creation
	st_blksize       The optimal I/O block size for the file.
	st_blocks        The actual number of blocks allocated for the file in
					 512-byte units
    st_mode         The status information word has the following bits
			S_IFMT 0170000           // type of file
					S_IFIFO  0010000  // named pipe (fifo)
					S_IFCHR  0020000  // character special
					S_IFDIR  0040000  // directory
					S_IFBLK  0060000  // block special
					S_IFREG  0100000  // regular
					S_IFLNK  0120000  // symbolic link
					S_IFSOCK 0140000  // socket
					S_IFWHT  0160000  // whiteout
			S_ISUID 0004000  // set user id on execution
			S_ISGID 0002000  // set group id on execution
			S_ISVTX 0001000  // save swapped text even after use
			S_IRUSR 0000400  // read permission, owner
			S_IWUSR 0000200  // write permission, owner
			S_IXUSR 0000100  // execute/search permission, owner
	RETURN:
		Upon successful completion a value of 0 is
		 returned.  Otherwise, a value of
		 -1 is returned and errno is set to indicate the error.
*/
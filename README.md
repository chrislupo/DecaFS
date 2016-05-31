DecaFS
=================
Distributed educational component adaptable File System

Starting DecaFS
---------------
First, install the executables.

 1. Copy the DecaFS source to the target system (e.g. one of your Raspberry Pis).
 2. Run `make` from the root of the source tree. This might take a while, but should complete successfully.
 3. Copy `bin/decafs_barista` to the home directory on one node, and `bin/decafs_espresso` to the home directory on each of the others. With appropriate modifications, `scripts/distribute_exe.sh` will do this.

Then, use the startup script either directly from one of your nodes or from a separate system.

 1. Make a copy of `scripts/sample_config.json` as e.g. `scripts/config.json`, changing the IP addresses to point to the nodes that have the appropriate executables.
 2. Run `python scripts/startup.py --config scripts/config.json`. This should print messages indicating that each of nodes 1-4 has started successfully.
 
Alternately, you can use [tmuxinator](https://github.com/tmuxinator/tmuxinator) to launch DecaFS. Running `tmuxinator decafs_local` from the root of the source tree will launch a local instance of DecaFS. The configuration file `scripts/decafs.yml` can be placed in `~/.tmuxinator/` and modified as appropriate to launch DecaFS on your cluster.

Troubleshooting DecaFS
----------------------
If DecaFS doesn't start correctly, this may be due to

 1. Leftover TCP connections from a recent run. The barista will print "Address already in use", espressos will print "Connection refused", and (on Linux) `netstat -atn|grep 3899` will show sockets in `TIME_WAIT` state. Wait a minute or two and try again.
 2. Corrupted persistent metadata. The barista will immediately crash with a segmentation fault. Delete `decafs_metadata*` files on the barista node (and optionally the espresso nodes, for a more complete reset) and try again.

Testing DecaFS
--------------
Once DecaFS is running, you can validate using a test client. From another terminal:

 1. Go to `src/app/decafs_test_client`
 2. Change the IP address in `main.cpp` to point to the barista node
 3. `make`
 4. Run `./nettest`

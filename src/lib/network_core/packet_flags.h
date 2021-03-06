#ifndef _PACKET_TYPES_
#define _PACKET_TYPES_

enum packet_flags {

   // Initialization Packets
   ESPRESSO_INIT,
   DECAFS_CLIENT_INIT,

   // Client -> Barista
   OPEN,
   READ,
   WRITE,
   CLOSE,
   LSEEK,
   REMOVE,
   SYNC,
   STAT_FS,
   MKDIR,
   OPENDIR,
   READDIR,
   FILE_STORAGE_STAT,

   // Barista -> Client
   OPEN_RESPONSE,
   READ_RESPONSE,
   WRITE_RESPONSE,
   CLOSE_RESPONSE,
   LSEEK_RESPONSE,
   REMOVE_RESPONSE,
   SYNC_RESPONSE,
   STAT_FS_RESPONSE,
   MKDIR_RESPONSE,
   OPENDIR_RESPONSE,
   READDIR_RESPONSE,
   FILE_STORAGE_STAT_RESPONSE,

   // Barista -> Espresso
   READ_CHUNK,
   WRITE_CHUNK,
   DELETE_CHUNK,

   // Espresso -> Barista
   READ_CHUNK_RESPONSE,
   WRITE_CHUNK_RESPONSE,
   DELETE_CHUNK_RESPONSE
};

#endif // _PACKET_TYPES_

/* Elastos Coin */

/* This file was written in 2017 by Yuan Xun. */

/* The license for this file has not yet been determined.
   Yuan Xun is hoping that some of these component files
   may be dual-licensed under the GPL and the Unlicense.
   Whereas the GPL is a strong libre license, the
   Unlicense is a weak libre license. This does not have
   to be a permanent arrangement. Mr Yuan would be
   contented if this happened only for the first one or
   two prereleases of Elastos Coin. That way, any useful
   subroutines of a customary nature contained within the
   codebase may be utilized by those who have possible
   disagreements with the GPL. */

/* The text of the Unlicense (without the second
   paragraph, which may not be necessary) is as follows: */

/* This is free and unencumbered software released into
   the public domain. Anyone is free to copy, modify,
   publish, use, compile, sell, or distribute this
   software, either in source code form or as a compiled
   binary, for any purpose, commercial or non-commercial,
   and by any means. In jurisdictions that recognize
   copyright laws, the author or authors of this software
   dedicate any and all copyright interest in the
   software to the public domain. We make this dedication
   for the benefit of the public at large and to the
   detriment of our heirs and successors. We intend this
   dedication to be an overt act of relinquishment in
   perpetuity of all present and future rights to this
   software under copyright law. */

/* The text of the GPL (the second version) is as
   follows: */

/* The text of the GPL (the third version) is as follows: */

struct _1022 {

   void *blocks;
   void *genesis;
   void *folder;
};

struct _0086 {

   void *current;
   void *next;
};

struct _0705 {

   void *identity;
   void *size;
   void *substance;
};

struct _0086 *build_3077(void *current, void *next) {

   struct _0086 *goal;

   goal = malloc(sizeof (struct _0086));
   goal->current = current;
   goal->next = next;

   return goal;
}

struct _0705 *build_4151(unsigned char *identity, int size, unsigned char *substance) {

   struct _0705 *goal;

   goal = malloc(sizeof (struct _0705));
   memcpy(goal->identity, identity, 32);
   goal->size = (void *) size;
   memcpy(goal->substance, substance, size);

   return goal;
}

struct _1022 *build_6668(unsigned char *genesis, unsigned char *folder) {

   struct _1022 *goal;

   goal = malloc(sizeof (struct _1022));
   goal->blocks = 0;
   memcpy(goal->genesis, genesis, 32);
   strcpy(goal->folder, folder);

   return goal;
}

struct _0086 *insert(struct _0086 *list, void *item) {

   return build_3077(item, list);
}

struct _0705 *retrieve(struct _0086 *cursor, unsigned char *identity) {

   struct _0705 *block;

   while (cursor != 0) {

      block = cursor->current;

      if (memcmp(identity, block->identity, 32) == 0)
         return block;

      cursor = cursor->next;
   }

   return 0;
}

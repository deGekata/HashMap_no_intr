// #include "Linked-list.hpp"
#include "Hash_table.hpp"
#include <vector>
#include <algorithm>
#include <string>

unsigned int _mm_encodekey128_u32 (unsigned int __htype, __m128i __key, void* __h);

char *randstring(size_t length) {

    static char charset[] = "abcdefghijklmnopqrstuvwxyz";        
    // static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!";        
    char *randomString = NULL;

    if (length) {
        randomString = (char*) malloc(sizeof(char) * (length +1));
        // randomString[0] = 'a';
        if (randomString) {            
            for (int n = 0;n < length;n++) {            
                int key = rand() % (int)(sizeof(charset) -1);
                randomString[n] = charset[key];
            }

            randomString[length] = '\0';
        }
    }

    return randomString;
}



#define DEBUG
// #undef DEBUG
const size_t insert_num_target = 1400000;
const size_t rand_str_len = 15;

int main() {
        
    Hashmap *map = HashmapCreate();
    Entry *tmp;
    bool lol = true; 
    std::vector<std::string> strings;
    for (size_t i = 0; i < insert_num_target; i++) {
        char* key = randstring(10 + rand() % rand_str_len + 1);
        char* value = randstring(10 + rand() % rand_str_len + 1);
        if (lol) {
            // printf("%s\n", key);
            lol = false;
        }
        // if (key[0] == 'a') {
        //     printf("key: %s,  value:%s\n", key, value);
        //     // printf("")
        // }
        Hashmap_insert(&map, key, value);
        // if (i % 10000 == 0) {
        //     printf("i = %d\n", i);
        //     printf("%d len\n", map->lists[0].capacity);
        //     printf("%d cap\n", map->capacity);
        // }
        // strings.push_back(std::string(key));
        free(key);
        free(value);
    }
    dprintf("%d line\n", __LINE__);
    // std::sort(strings.begin(), strings.end());
    dprintf("%d line\n", __LINE__);
    // for (int it = 0; it < strings.size(); ++it) {
    //     printf("key: %s\n", strings[it].c_str());
    // }
    // printf("%d line\n", __LINE__);
    
#ifdef DEBUG
    int* vals = (int*) malloc(sizeof(int) * map->capacity);
    FILE* stats = fopen("temp.txt", "w");
    fprintf(stats, "hash_num, bucket_size\n");
    // printf("%d line\n", __LINE__);
    // printf("%ld\n", (int64_t)stats);
    // printf("%d line\n", __LINE__);
    int cnt = 0;
    int sum = 0, non_zero = 0;
    for (size_t i = 0; i < map->capacity; i++) {
        fprintf(stats, "%lu,\t%lu\n", i, map->lists[i].size);
        vals[i] = map->lists[i].size;
        cnt += map->lists[i].size;
        if ( map->lists[i].size) {
            sum += map->lists[i].size;
            ++non_zero;
        }
        // printf("ind:%lu ", i);
        // printlist(&map->lists[i]);

    }
    fclose(stats);
    printf("%d size\n", cnt);
    free(vals);
    
#endif
    dprintf("%d line\n", __LINE__);
    // aligned_alloc()
    char* mmm = (char*) _aligned_malloc(1000, 1024);
    printf("1024-byte aligned addr: %p\n", (void*)mmm);
    dprintf("%d line\n", __LINE__);
    mmxi_t _255(8);
    dprintf("%d line\n", __LINE__);
    int res = 0;
    // int res = _mm_encodekey128_u32(12, _255, mmm);
    dprintf("%d line\n", __LINE__);
    destroyHashmap(&map);
    dprintf("%d line\n", __LINE__);
    dprintf("%f mid\n", (float) sum / non_zero);
    uint64_t a = 10, b = 5;
    char* m_str = "abcde";

    printf("%lu %lu", a, b);
    return 0;
} 


// uint64_t a = 10, b = 5;
//     char* m_str = "abcde";
//     __asm__ ( ".intel_syntax noprefix\n\t"
//         "mov rsi, %1\n\t"
//         "mov rbx, 1234\n\t" /* ???????????????????????? ?????????????? */
//         "mov rcx, 0\n\t" /* ???????????????????????? ?????????????? */
//         "mov rax, 0\n\t"
//         "begin:\n\t" /* ???????????????????????? ?????????????? */
//         "lodsb \n\t"
//         "test al, al\n\t"
//         "je end\n\t"
//         "mov rcx, rbx\n\t"
//         "shl rbx, 7\n\t"
//         // "xor rbx, rax\n\t"
//         "add rbx, rcx\n\t"
//         "xor rbx, rax\n\t"
//         "jmp begin\n\t"
//         "end:\n\t"
//         "mov %0, rbx\n\t"
//         ".att_syntax\n\t"
//         : "=r"(b) /* ???????????????? ???????????????? */
//         : "r"(m_str) /* ?????????????? ???????????????? */
//         : "%rsi", "%rax", "%rcx", "%rbx" /* ?????????????????????? ???????????????? */

//         );



// uint64_t strHashCode(char* str) {
//     uint64_t hash = 1234;
//     while (*str) {
//         hash = ((hash << 7) + hash) ^ *(str++);
//     }

//     return hash;
// }
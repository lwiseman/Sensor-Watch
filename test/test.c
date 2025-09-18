#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>

int main() {
	typedef union {
		struct {
			uint8_t seg __attribute((aligned(2)));
			uint8_t com __attribute((aligned(2)));
		};
		uint32_t word;
	} segid_t;

	segid_t SLCD_SEGID(uint8_t com, uint8_t seg) {
		return (segid_t){ seg, com };
	}
	uint8_t SLCD_COMNUM(segid_t segid) {
		return segid.com;
	}
	uint8_t SLCD_SEGNUM(segid_t segid) {
		return segid.seg;
	}

	// TODO: this doesn't seem to initialize other bytes
	segid_t segid;
	static_assert(sizeof(segid_t) == 4);
	memset(&segid, 0, 4);
	//segid = SLCD_SEGID(7, 2);
	segid.com = 7;
	segid.seg = 2;
	uint8_t com = SLCD_COMNUM(segid);
	uint8_t seg = SLCD_SEGNUM(segid);

	uint32_t segid2 = (7 << 16) | 2;

	//printf("(%d, %d) = %d at %ld bytes\n", test.com, test.segment, test.word, sizeof(test));
	printf("(%u, %u) = %x\n", com, seg, segid.word);
	printf("%x\n", segid2);

	//

	segid_t D1a = SLCD_SEGID(0, 1);
	segid_t D1b = SLCD_SEGID(0, 2);
	segid_t D1c = SLCD_SEGID(0, 3);
	segid_t D1d = SLCD_SEGID(0, 4);
	segid_t D1e = SLCD_SEGID(0, 5);
	segid_t D1f = SLCD_SEGID(0, 6);
	segid_t D1g = SLCD_SEGID(0, 7);
	segid_t P0 = SLCD_SEGID(0, 8);
	segid_t* Segment_Map[][8] = {
		{ NULL, &D1b, &D1c, NULL, NULL, NULL, &D1g, NULL },
		{ &D1a, &D1b, &D1c, &D1d, &D1e, &D1f, &D1g, NULL }
	};

	for(int position = 0; position < sizeof(Segment_Map) / sizeof(*Segment_Map); ++position) {
		for(int segid = 0; segid < sizeof(Segment_Map[0]) / sizeof(*Segment_Map[0]); ++segid) {
			segid_t* current_ptr = Segment_Map[position][segid];
			if(current_ptr == NULL)
				continue;
			printf("(%d, %d) ", SLCD_COMNUM(*current_ptr), SLCD_SEGNUM(*current_ptr));
		}
		printf("\n");
	}

	return 0;
}


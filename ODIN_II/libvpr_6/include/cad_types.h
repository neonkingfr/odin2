/* 
Data types used to give architectural hints for the CAD algorithm 
*/
#ifndef CAD_TYPES_H
#define CAD_TYPES_H

#include "logic_types.h"
#include "physical_types.h"
#include "util.h"

struct s_pack_pattern_connections;
typedef struct s_pack_pattern_block
{
	int pattern_index;								/* index of pattern that this block is a part of */
	const t_pb_type *pb_type;								/* pb_type that this block is an instance of */
	struct s_pack_pattern_connections *connections;	/* linked list of connections of logic blocks in pattern */	
	int block_id;
} t_pack_pattern_block;

/* Describes connections of s_pack_pattern_block */
typedef struct s_pack_pattern_connections
{
	t_pack_pattern_block *from_block;
	t_pb_graph_pin *from_pin;

	t_pack_pattern_block *to_block;
	t_pb_graph_pin *to_pin;

	struct s_pack_pattern_connections *next;
} t_pack_pattern_connections;


typedef struct s_pack_patterns
{
	char *name;									/* name of this logic model pattern */
	int index;                                  /* array index  for pattern*/
	t_pack_pattern_block *root_block;			/* root block used by this pattern */
	int block_count;							/* number of blocks in pattern */
} t_pack_patterns;

typedef struct s_model_chain_pattern
{
	char *name;								/* name of this chain of logic */
	t_model *model;			/* block associated with chain */
	t_model_ports *input_link_port;			/* pointer to port of chain input */
	int inport_link_pin;					/* applicable pin of chain input port */
	t_model_ports *output_link_port;			/* pointer to port of chain output */
	int outport_link_pin;					/* applicable pin of chain output port */
	struct s_model_chain_pattern *next;		/* next chain (linked list) */
} t_model_chain_pattern;



/**
 * Keeps track of locations that a primitive can go to during packing
 * Linked list for easy insertion/deletion
 */
typedef struct s_cluster_placement_primitive
{
	t_pb_graph_node *pb_graph_node;
	struct s_cluster_placement_primitive *next_primitive;
	boolean valid;	
	float base_cost;		/* cost independant of current status of packing */
	float incremental_cost; /* cost dependant on current status of packing */
} t_cluster_placement_primitive;


#endif

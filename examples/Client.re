module GraphFragment = [%graphql
  {|
     fragment personFields on Person {
      id
      age
      name
     }
   |}
];

module PersonFragment = ApolloClientReadFragment.ReadFragment(GraphFragment.PersonFields);

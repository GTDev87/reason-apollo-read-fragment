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

let get = (~fragmentType: string, ~id: string, ~fragmentName: string): option(GraphFragment.PersonFields.t) =>
  PersonFragment.read(
    ~client=Client.instance,
    ~id=fragmentType ++ ":" ++ id,
    ~fragmentName,
    (),
  );
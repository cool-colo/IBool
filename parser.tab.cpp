// A Bison parser, made by GNU Bison 3.0.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2013 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "parser.tab.cpp" // lalr1.cc:399

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parser.tab.hpp"

// User implementation prologue.

#line 51 "parser.tab.cpp" // lalr1.cc:407
// Unqualified %code blocks.
#line 20 "parser.ypp" // lalr1.cc:408

  #include "lexer.h"
  
  #define yylex lexer.lex

#line 59 "parser.tab.cpp" // lalr1.cc:408


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif



// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyempty = true)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 4 "parser.ypp" // lalr1.cc:474
namespace Bool {
#line 126 "parser.tab.cpp" // lalr1.cc:474

  /// Build a parser object.
  Parser::Parser (Bool::Lexer& lexer_yyarg, Expression** result_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      lexer (lexer_yyarg),
      result (result_yyarg)
  {}

  Parser::~Parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  Parser::syntax_error::syntax_error (const std::string& m)
    : std::runtime_error (m)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
  {
    value = other.value;
  }


  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v)
    : Base (t)
    , value (v)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  inline
  Parser::basic_symbol<Base>::~basic_symbol ()
  {
  }

  template <typename Base>
  inline
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
  }

  // by_type.
  inline
  Parser::by_type::by_type ()
     : type (empty)
  {}

  inline
  Parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.type = empty;
  }

  inline
  int
  Parser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  Parser::by_state::by_state ()
    : state (empty)
  {}

  inline
  Parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.state = empty;
  }

  inline
  Parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  Parser::symbol_number_type
  Parser::by_state::type_get () const
  {
    return state == empty ? 0 : yystos_[state];
  }

  inline
  Parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  Parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s)
  {
    value = that.value;
    // that is emptied.
    that.type = empty;
  }

  inline
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    return *this;
  }


  template <typename Base>
  inline
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  Parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  Parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  Parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::parse ()
  {
    /// Whether yyla contains a lookahead.
    bool yyempty = true;

    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyempty)
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
        yyempty = false;
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Discard the token being shifted.
    yyempty = true;

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;


      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 63 "parser.ypp" // lalr1.cc:847
    {*result = (yystack_[0].value.expression);}
#line 523 "parser.tab.cpp" // lalr1.cc:847
    break;

  case 3:
#line 67 "parser.ypp" // lalr1.cc:847
    { (yylhs.value.expression) = ExpressionMaker::MakeAndAlsoExpression(std::string((yystack_[1].value.token)), (yystack_[2].value.expression), (yystack_[0].value.expression)); std::cout<<"AndAlso:"<<(yystack_[1].value.token)<<std::endl; }
#line 529 "parser.tab.cpp" // lalr1.cc:847
    break;

  case 4:
#line 68 "parser.ypp" // lalr1.cc:847
    { (yylhs.value.expression) = ExpressionMaker::MakeOrElseExpression(std::string((yystack_[1].value.token)), (yystack_[2].value.expression), (yystack_[0].value.expression)); std::cout<<"OrElse:"<<(yystack_[1].value.token)<<std::endl; }
#line 535 "parser.tab.cpp" // lalr1.cc:847
    break;

  case 5:
#line 69 "parser.ypp" // lalr1.cc:847
    { (yylhs.value.expression) = ExpressionMaker::MakeNotExpression(std::string((yystack_[1].value.token)), (yystack_[0].value.expression));  std::cout<<"Not:"<<(yystack_[1].value.token)<<std::endl;}
#line 541 "parser.tab.cpp" // lalr1.cc:847
    break;

  case 6:
#line 70 "parser.ypp" // lalr1.cc:847
    { (yylhs.value.expression) = ExpressionMaker::MakeEqualExpression(std::string((yystack_[1].value.token)), std::string((yystack_[2].value.token)), std::string((yystack_[0].value.token))); std::cout<<"Equal:"<<(yystack_[1].value.token)<<std::endl;}
#line 547 "parser.tab.cpp" // lalr1.cc:847
    break;

  case 7:
#line 71 "parser.ypp" // lalr1.cc:847
    { (yylhs.value.expression) = ExpressionMaker::MakeNotEqualExpression(std::string((yystack_[1].value.token)), std::string((yystack_[2].value.token)), std::string((yystack_[0].value.token))); std::cout<<"NotEqual:"<<(yystack_[1].value.token)<<std::endl; }
#line 553 "parser.tab.cpp" // lalr1.cc:847
    break;

  case 8:
#line 72 "parser.ypp" // lalr1.cc:847
    { (yylhs.value.expression) = ExpressionMaker::MakeGreaterThanExpression(std::string((yystack_[1].value.token)), std::string((yystack_[2].value.token)), std::string((yystack_[0].value.token))); std::cout<<"GreaterThan:"<<(yystack_[1].value.token)<<std::endl; }
#line 559 "parser.tab.cpp" // lalr1.cc:847
    break;

  case 9:
#line 73 "parser.ypp" // lalr1.cc:847
    { (yylhs.value.expression) = ExpressionMaker::MakeGreaterThanOrEqualExpression(std::string((yystack_[1].value.token)), std::string((yystack_[2].value.token)), std::string((yystack_[0].value.token))); std::cout<<"GreaterThanOrEqual:"<<(yystack_[1].value.token)<<std::endl; }
#line 565 "parser.tab.cpp" // lalr1.cc:847
    break;

  case 10:
#line 74 "parser.ypp" // lalr1.cc:847
    { (yylhs.value.expression) = ExpressionMaker::MakeLessThanExpression(std::string((yystack_[1].value.token)), std::string((yystack_[2].value.token)), std::string((yystack_[0].value.token))); std::cout<<"LessThan:"<<(yystack_[1].value.token)<<std::endl; }
#line 571 "parser.tab.cpp" // lalr1.cc:847
    break;

  case 11:
#line 75 "parser.ypp" // lalr1.cc:847
    { (yylhs.value.expression) = ExpressionMaker::MakeLessThanOrEqualExpression(std::string((yystack_[1].value.token)), std::string((yystack_[2].value.token)), std::string((yystack_[0].value.token))); std::cout<<"LessThanOrEqual:"<<(yystack_[1].value.token)<<std::endl; }
#line 577 "parser.tab.cpp" // lalr1.cc:847
    break;

  case 12:
#line 76 "parser.ypp" // lalr1.cc:847
    { (yylhs.value.expression) = ExpressionMaker::MakeContainsExpression(std::string((yystack_[1].value.token)), std::string((yystack_[2].value.token)), std::string((yystack_[0].value.token))); std::cout<<"Contains:"<<(yystack_[1].value.token)<<std::endl; }
#line 583 "parser.tab.cpp" // lalr1.cc:847
    break;

  case 13:
#line 77 "parser.ypp" // lalr1.cc:847
    { (yylhs.value.expression) = ExpressionMaker::MakeInExpression(std::string((yystack_[1].value.token)), std::string((yystack_[2].value.token)), std::string((yystack_[0].value.token))); std::cout<<"In:"<<(yystack_[1].value.token)<<std::endl; }
#line 589 "parser.tab.cpp" // lalr1.cc:847
    break;

  case 14:
#line 78 "parser.ypp" // lalr1.cc:847
    { (yylhs.value.expression) = ExpressionMaker::MakeNotInExpression(std::string((yystack_[1].value.token)), std::string((yystack_[2].value.token)), std::string((yystack_[0].value.token))); std::cout<<"NotIn:"<<(yystack_[1].value.token)<<std::endl; }
#line 595 "parser.tab.cpp" // lalr1.cc:847
    break;

  case 15:
#line 79 "parser.ypp" // lalr1.cc:847
    { (yylhs.value.expression) = (yystack_[1].value.expression); }
#line 601 "parser.tab.cpp" // lalr1.cc:847
    break;


#line 605 "parser.tab.cpp" // lalr1.cc:847
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state,
                                           yyempty ? yyempty_ : yyla.type_get ()));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyempty)
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyempty = true;
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyempty)
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyempty)
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type, symbol_number_type) const
  {
    return YY_("syntax error");
  }


  const signed char Parser::yypact_ninf_ = -3;

  const signed char Parser::yytable_ninf_ = -1;

  const signed char
  Parser::yypact_[] =
  {
       0,    14,     0,     0,     2,    -1,     7,     8,     9,    10,
      11,    15,    16,    27,    29,    -3,     3,    -3,     0,     0,
      -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,
      -3,     1
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       0,     0,     0,     0,     0,     2,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     0,     1,     0,     0,
       6,     7,     8,     9,    10,    11,    13,    14,    12,    15,
       3,     4
  };

  const signed char
  Parser::yypgoto_[] =
  {
      -3,    -3,    -2
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,     4,     5
  };

  const unsigned char
  Parser::yytable_[] =
  {
      15,    16,    17,     1,     0,    18,    19,    18,     2,    18,
      19,    20,    21,    22,    23,    24,    30,    31,     3,    25,
       0,    26,    29,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    27,    28
  };

  const signed char
  Parser::yycheck_[] =
  {
       2,     3,     0,     3,    -1,     6,     7,     6,     8,     6,
       7,     4,     4,     4,     4,     4,    18,    19,    18,     4,
      -1,     5,    19,     9,    10,    11,    12,    13,    14,    15,
      16,    17,     5,     4
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,     3,     8,    18,    21,    22,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    22,    22,     0,     6,     7,
       4,     4,     4,     4,     4,     4,     5,     5,     4,    19,
      22,    22
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    20,    21,    22,    22,    22,    22,    22,    22,    22,
      22,    22,    22,    22,    22,    22
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     1,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "TOKEN_END", "error", "$undefined", "TOKEN_DYNAMIC_VAR",
  "TOKEN_CONST_VAR", "TOKEN_CONST_LIST", "TOKEN_LOGIC_OP_AND",
  "TOKEN_LOGIC_OP_OR", "TOKEN_LOGIC_OP_NOT", "TOKEN_RELATION_OP_EQ",
  "TOKEN_RELATION_OP_NE", "TOKEN_RELATION_OP_GT", "TOKEN_RELATION_OP_GTE",
  "TOKEN_RELATION_OP_LT", "TOKEN_RELATION_OP_LTE", "TOKEN_RELATION_OP_IN",
  "TOKEN_RELATION_OP_NIN", "TOKEN_RELATION_OP_CTN", "TOKEN_LPAREN",
  "TOKEN_RPAREN", "$accept", "input", "expr", YY_NULLPTR
  };


  const unsigned char
  Parser::yyrline_[] =
  {
       0,    63,    63,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19
    };
    const unsigned int user_token_number_max_ = 274;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 4 "parser.ypp" // lalr1.cc:1155
} // Bool
#line 946 "parser.tab.cpp" // lalr1.cc:1155
#line 83 "parser.ypp" // lalr1.cc:1156


void yyerror (char const *s)
{
  fprintf (stderr, "%s\n", s);
}

void error(const std::string& msg)
{
  std::cerr << "error message: " << msg << '\n';
}

